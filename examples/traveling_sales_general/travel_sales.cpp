//traveling salesman initialization and energy functions

#include "travel_sales.h"
#include <iostream>
using namespace std;

int * min_ord;
int pd_val;
int nc_val;
double min_len=1.0E+308;

// customer locations
double ** cust_locs;

//traveling salesman initialization problem
void ts_init(int num_customers, int prob_dim){
  int i,j;
  double num_perms, est_time;

  pd_val=prob_dim;
  nc_val=num_customers;

  cust_locs = new double*[num_customers];
  for(i=0; i<num_customers; i++){
    cust_locs[i] = new double[prob_dim];
    for(j=0; j<prob_dim; j++){
      cust_locs[i][j]=(double)rand()/(double)RAND_MAX;
    }
  }

  //compute number of permutations and initialize the first permutation (just ordered)
  min_ord = new int[num_customers];
  num_perms=1.0;
  for(i=0; i<num_customers; i++){
    num_perms=num_perms*(i+1);
    min_ord[i]=i;
  }
  cout << "number of possible paths: " << num_perms << endl;

  //estimate time for brute force calculation (estimated using Fortran)
  est_time=num_perms*num_customers*prob_dim*2.0E-9;
  if(est_time > 365.0*24.0*60.0*60.0){
    cout << "Estimated brute force calculation time " << est_time/(365.0*24.0*60.0*60.0) << " years." << endl;
  }
  else if(est_time > 24.0*60.0*60.0){
    cout << "Estimated brute force calculation time " << est_time/(24.0*60.0*60.0) << " days." << endl;
  }
  else if(est_time > 60.0*60.0){
    cout << "Estimated brute force calculation time " << est_time/(60.0*60.0) << " hours." << endl;
  }
  else if(est_time > 60.0){
    cout << "Estimated brute force calculation time " << est_time/(60.0) << " minutes." << endl;
  }
  else{
    cout << "Estimated brute force calculation time " << est_time << " seconds." << endl;
  }

  // if 1D, compute the minimum length using a bubble sort
  min_len=0;
  if(prob_dim == 1){
    bubble_sort(min_ord);
    min_len=path_len(min_ord);
    cout << "1D Computed minimum path length:  " << min_len << " or " << cust_locs[min_ord[num_customers-1]][0]-cust_locs[min_ord[0]][0] << endl;
  }
}

double path_len(int * state_ord){
  int i;
  double comp_val;

  comp_val=0.0;
  for(i=0; i<nc_val-1; i++){
    comp_val+=dist(cust_locs[state_ord[i]], cust_locs[state_ord[i+1]]);
  }
  return comp_val;
}

double dist(double *loc1, double *loc2){
  int i;
  double dist_val;

  dist_val=0.0;
  for(i=0; i<pd_val; i++){
    dist_val+=pow(loc1[i]-loc2[i],2);
  }
  dist_val=sqrt(dist_val);

  return dist_val;
}

void bubble_sort(int *a){
  int i,j,temp_i;
  bool swapped;

  for(j=nc_val-1; j>0; j--){
    swapped=false;
    for(i=0; i<j; i++){
      if(cust_locs[a[i]][0] > cust_locs[a[i+1]][0]){
        temp_i=a[i];
        a[i]=a[i+1];
        a[i+1]=temp_i;
        swapped=true;
      }
    }
    if(!swapped)break;
  }
}

//sets up the traveling salesman simulated annealing problem
void setup_ts_sa(sa_comb_type &this_sa){
  int i;

  this_sa.max_step=10000*nc_val;
  this_sa.t_max=100;
  this_sa.t_min=0;
  this_sa.cool_opt="QuadAdd";
  this_sa.mon_cool=false;
  this_sa.prog_bar=true;
  this_sa.state_curr=new int[nc_val];
  //default initial guess to original order
  this_sa.state_size=nc_val;
  for(i=0; i<nc_val; i++){
    this_sa.state_curr[i]=i;
  }
  //point to a path length function that works with the SA type
  this_sa.energy=&path_len;
}
