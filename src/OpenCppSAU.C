// OpenCppSAU is a C++ version of OpenFSAM

#include "OpenCppSAU.h"
#include <iostream>

using namespace std;

// Optimization subroutine for the base class, valid for both types
void sa_type_base::optimize(sa_type_base &my_sa){
  int i;
  double e_curr;

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
  }
  else{
    cout << "error, bad simulated annealing type" << endl;
    exit(1);
  }
}