// OpenCppSAU is a C++ version of OpenFSAM

#include "OpenCppSAU.h"

using namespace std;

// Optimization subroutine for the base class, valid for both types
void sa_type_base::optimize(sa_type_base &my_sa){
  int i, step;
  double e_curr, t_curr;
  e_curr=100000.0E0;

  set_cooling(my_sa);

  if(sa_comb_type *sa_ptr = dynamic_cast<sa_comb_type*>(&my_sa)){
    // allocate potentially unallocated data
    if(sa_ptr->state_neigh == NULL){
      sa_ptr->state_neigh = new int [my_sa.state_size];
    }
    if(sa_ptr->state_best == NULL){
      sa_ptr->state_best = new int [my_sa.state_size];
    }
    for(i=0; i<my_sa.state_size; i++){
      sa_ptr->state_neigh[i]=sa_ptr->state_curr[i];
      sa_ptr->state_best[i]=sa_ptr->state_curr[i];
    }
    //set energy to current energy
    e_curr=sa_ptr->energy(sa_ptr->state_curr);
    sa_ptr->e_best=e_curr;
  }
  else if(sa_cont_type *sa_ptr = dynamic_cast<sa_cont_type*>(&my_sa)){
    // allocate potentially unallocated data
    if(sa_ptr->state_neigh == NULL){
      sa_ptr->state_neigh = new double [my_sa.state_size];
    }
    if(sa_ptr->state_best == NULL){
      sa_ptr->state_best = new double [my_sa.state_size];
    }
    for(i=0; i<my_sa.state_size; i++){
      sa_ptr->state_neigh[i]=sa_ptr->state_curr[i];
      sa_ptr->state_best[i]=sa_ptr->state_curr[i];
    }
    //set energy to current energy
    e_curr=sa_ptr->energy(sa_ptr->state_curr);
    sa_ptr->e_best=e_curr;
    //set bounds of state if not given
    if(abs(sa_ptr->smin-sa_ptr->smax) < 1.0E-13){
      sa_ptr->smin=1.0E+300;
      sa_ptr->smax=-1.0E+300;
      for(i=0; i<my_sa.state_size; i++){
        if(sa_ptr->smin > sa_ptr->state_curr[i]){
          sa_ptr->smin=sa_ptr->state_curr[i];
        }
        if(sa_ptr->smax < sa_ptr->state_curr[i]){
          sa_ptr->smax=sa_ptr->state_curr[i];
        }
      }
    }
    if(sa_ptr->damping <= 1.0E-15)sa_ptr->damping=abs(sa_ptr->smax-sa_ptr->smin)/2.0E+0;
  }
  else{
    cout << "error, bad simulated annealing type" << endl;
    exit(1);
  }
  t_curr=my_sa.t_max;
  step=0;
  cout << t_curr << " " << step << endl;
  my_sa.total_steps=0;
  if(my_sa.prog_bar)cout << "PROGRESS:";
  while(step < my_sa.max_step && t_curr > my_sa.t_min){
    my_sa.total_steps++;
    if(sa_comb_type *sa_ptr = dynamic_cast<sa_comb_type*>(&my_sa)){
      sa_ptr->get_neigh(sa_ptr->state_curr, sa_ptr->state_neigh, my_sa.state_size);
    }
    else if(sa_cont_type *sa_ptr = dynamic_cast<sa_cont_type*>(&my_sa)){
      sa_ptr->get_neigh(sa_ptr->state_curr, sa_ptr->state_neigh, sa_ptr->damping, sa_ptr->smax, sa_ptr->smin, sa_ptr->num_perturb, my_sa.state_size);
    }
    step++;
    exit(1);
    cout << my_sa.total_steps << endl;
  }
}

void set_cooling(sa_type_base &my_sa){
  if(my_sa.cool_opt == "LinMult"){
    my_sa.cool=&lin_mult_cool;
  }
  else if(my_sa.cool_opt == "ExpMult"){
    my_sa.cool=&exp_mult_cool;
  }
  else if(my_sa.cool_opt == "LogMult"){
    my_sa.cool=&log_mult_cool;
  }
  else if(my_sa.cool_opt == "QuadMult"){
    my_sa.cool=&quad_mult_cool;
  }
  else if(my_sa.cool_opt == "LinAdd"){
    my_sa.cool=&lin_add_cool;
  }
  else if(my_sa.cool_opt == "QuadAdd"){
    my_sa.cool=&quad_add_cool;
  }
  else if(my_sa.cool_opt == "ExpAdd"){
    my_sa.cool=&exp_add_cool;
  }
  else if(my_sa.cool_opt == "TrigAdd"){
    my_sa.cool=&trig_add_cool;
  }
  else if(my_sa.cool_opt == "custom"){
    cout << "Using user specified cooling function." << endl;
  }
  else{
    cout << "error, bad cooling specification " << my_sa.cool_opt << endl;
    exit(1);
  }
}

double lin_mult_cool(sa_type_base &my_sa, int k){
  return my_sa.t_max/(1.0E0+my_sa.alpha*k);
}

double exp_mult_cool(sa_type_base &my_sa, int k){
  return my_sa.t_max*pow(my_sa.alpha,k);
}

double log_mult_cool(sa_type_base &my_sa, int k){
  return my_sa.t_max/(1.0E0+my_sa.alpha*log10(k+1.0E0));
}

double quad_mult_cool(sa_type_base &my_sa, int k){
  return my_sa.t_max/(1.0+my_sa.alpha*pow(k*1.0E0,2));
}

double lin_add_cool(sa_type_base &my_sa, int k){
  return my_sa.t_min+(my_sa.t_max-my_sa.t_min)*(my_sa.max_step*1.0E0-k)/(my_sa.max_step*1.0E0);
}

double quad_add_cool(sa_type_base &my_sa, int k){
  return my_sa.t_min+(my_sa.t_max-my_sa.t_min)*pow((my_sa.max_step*1.0E0-k)/(my_sa.max_step*1.0E0),2);
}

double exp_add_cool(sa_type_base &my_sa, int k){
  return my_sa.t_min+(my_sa.t_max-my_sa.t_min)/(1.0E0+exp(2.0E0*log(my_sa.t_max-my_sa.t_min)*(k-0.5E0*my_sa.max_step)/(my_sa.max_step*1.0E0)));
}

double trig_add_cool(sa_type_base &my_sa, int k){
  return my_sa.t_min+0.5E0*(my_sa.t_max-my_sa.t_min)*(1.0E0+cos(k*M_PI/(my_sa.max_step*1.0E0)));
}

void sa_comb_type::get_neigh(int *s_curr, int *s_neigh, int size_state){
  int i, j1, j2;
  double diff;
  for(i=0; i < size_state; i++){
    s_neigh[i]=s_curr[i];
  }
  diff=0.0;
  while(abs(diff) < 1.0E-15){
    j1=(rand() % size_state);
    j2=(rand() % size_state);
    s_neigh[j1]=s_curr[j2];
    s_neigh[j2]=s_curr[j1];
    diff=0.0;
    for(i=0; i < size_state; i++){
      diff=abs(1.0*s_neigh[i]-1.0*s_curr[i]);
    }
  }
}
/*
*--------------------------------------------------------------------------------------------------
* @brief This function gets a new neighbor state for a continuous annealing problem
* @param s_curr - the current state
* @param s_neigh - the neighbor state
* @param damping - the damping factor
* @param smax - maximum state value
* @param smin - minimum state value
* @param size_state - dimensionality of the state
*/
void sa_cont_type::get_neigh(double *s_curr, double *s_neigh, double damping, double smax, double smin, int num_perturb, int size_state){
  int i, temp_i, j;
  double temp_r;
  int * perturb_locs = NULL;
  for(i=0; i < size_state; i++){
    s_neigh[i]=s_curr[i];
  }
  cout << s_neigh[0] << endl;
  if(num_perturb <= 0 || num_perturb >= size_state){
    for(i=0; i < size_state; i++){
      temp_r=(double)rand()/(double)RAND_MAX;
      s_neigh[i]=s_curr[i]+(1.0-2.0*temp_r)*damping;

      if(s_neigh[i] >= smax){
        s_neigh[i]=smax;
      }
      else if(s_neigh[i] <= smin){
        s_neigh[i]=smin;
      }
    }
  }
  else{
    perturb_locs = new int [num_perturb];
    for(i=0; i < num_perturb; i++){
      perturb_locs[i]=-1;
    }
    i=0;
    while(i <= num_perturb){
      temp_i=rand() % size_state;
      j=i;
      for(j=0; j < i; j++){
        if(perturb_locs[j] == temp_i)break;
      }
      if(j == i){
        perturb_locs[j]=temp_i;
        i++;
      }
    }
    for(j=0; j < num_perturb; j++){
      i=perturb_locs[j];
      temp_r=(double)rand()/(double)RAND_MAX;
      s_neigh[i]=s_curr[i]+(1.0-2.0*temp_r)*damping;

      if(s_neigh[i] >= smax){
        s_neigh[i]=smax;
      }
      else if(s_neigh[i] <= smin){
        s_neigh[i]=smin;
      }
    }
  }

  cout << s_neigh[0] << endl;
}