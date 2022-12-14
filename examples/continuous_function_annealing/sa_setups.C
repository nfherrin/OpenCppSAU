// The functions that the simulated annealing calculation will optimize over.

#include "sa_setups.h"

void setup_sa_func1(sa_cont_type &func_sa, int max_step, double t_max, double t_min,
                    std::string cool_opt, bool mon_cool, double smin, double smax, double damping,
                    double resvar, bool damp_dyn){
  // Base information, see main.h for the given parameters.
  func_sa.max_step=max_step;
  func_sa.t_max=t_max;
  func_sa.t_min=t_min;
  func_sa.cool_opt=cool_opt;
  func_sa.mon_cool=mon_cool;
  func_sa.smin=smin;
  func_sa.smax=smax;
  func_sa.damping=damping;
  func_sa.resvar=resvar;
  func_sa.damp_dyn=damp_dyn;
  func_sa.prog_bar=true;
  // give energy function
  func_sa.energy=&func1;
  // give random initial guess
  func_sa.state_size=1;
  func_sa.state_curr=new double [func_sa.state_size];
  func_sa.state_curr[0]=(double)rand()/(double)RAND_MAX;
  func_sa.state_curr[0]=func_sa.state_curr[0]*2.0E+1-1.0E+1;
  return;
}

void setup_sa_func2(sa_cont_type &func_sa, int max_step, double t_max, double t_min,
                    std::string cool_opt, bool mon_cool, double smin, double smax, double damping,
                    double resvar, bool damp_dyn){
  // Base information, see main.h for the given parameters.
  func_sa.max_step=max_step;
  func_sa.t_max=t_max;
  func_sa.t_min=t_min;
  func_sa.cool_opt=cool_opt;
  func_sa.mon_cool=mon_cool;
  func_sa.smin=smin;
  func_sa.smax=smax;
  func_sa.damping=damping;
  func_sa.resvar=resvar;
  func_sa.damp_dyn=damp_dyn;
  func_sa.prog_bar=true;
  // give energy function
  func_sa.energy=&func2;
  // give random initial guess
  func_sa.state_size=1;
  func_sa.state_curr=new double [func_sa.state_size];
  func_sa.state_curr[0]=(double)rand()/(double)RAND_MAX;
  func_sa.state_curr[0]=func_sa.state_curr[0]*2.0E+1-1.0E+1;
  return;
}

void setup_sa_func3(sa_cont_type &func_sa, int max_step, double t_max, double t_min,
                    std::string cool_opt, bool mon_cool, double smin, double smax, double damping,
                    double resvar, bool damp_dyn){
  // Base information, see main.h for the given parameters.
  func_sa.max_step=max_step;
  func_sa.t_max=t_max;
  func_sa.t_min=t_min;
  func_sa.cool_opt=cool_opt;
  func_sa.mon_cool=mon_cool;
  func_sa.smin=smin;
  func_sa.smax=smax;
  func_sa.damping=damping;
  func_sa.resvar=resvar;
  func_sa.damp_dyn=damp_dyn;
  func_sa.prog_bar=true;
  // give energy function
  func_sa.energy=&func3;
  // give random initial guess
  func_sa.state_size=1;
  func_sa.state_curr=new double [func_sa.state_size];
  func_sa.state_curr[0]=(double)rand()/(double)RAND_MAX;
  func_sa.state_curr[0]=func_sa.state_curr[0]*2.0E+1-1.0E+1;
  return;
}

void setup_sa_func4(sa_cont_type &func_sa, int max_step, double t_max, double t_min,
                    std::string cool_opt, bool mon_cool, double smin, double smax, double damping,
                    double resvar, bool damp_dyn){
  // Base information, see main.h for the given parameters.
  func_sa.max_step=max_step;
  func_sa.t_max=t_max;
  func_sa.t_min=t_min;
  func_sa.cool_opt=cool_opt;
  func_sa.mon_cool=mon_cool;
  func_sa.smin=smin;
  func_sa.smax=smax;
  func_sa.damping=damping;
  func_sa.resvar=resvar;
  func_sa.damp_dyn=damp_dyn;
  func_sa.prog_bar=true;
  // give energy function
  func_sa.energy=&func4;
  // give random initial guess
  func_sa.state_size=1;
  func_sa.state_curr=new double [func_sa.state_size];
  func_sa.state_curr[0]=(double)rand()/(double)RAND_MAX;
  func_sa.state_curr[0]=func_sa.state_curr[0]*2.0E+1-1.0E+1;
  return;
}

void setup_sa_func5(sa_cont_type &func_sa, int max_step, double t_max, double t_min,
                    std::string cool_opt, bool mon_cool, double smin, double smax, double damping,
                    double resvar, bool damp_dyn){
  // Base information, see main.h for the given parameters.
  func_sa.max_step=max_step;
  func_sa.t_max=t_max;
  func_sa.t_min=t_min;
  func_sa.cool_opt=cool_opt;
  func_sa.mon_cool=mon_cool;
  func_sa.smin=smin;
  func_sa.smax=smax;
  func_sa.damping=damping;
  func_sa.resvar=resvar;
  func_sa.damp_dyn=damp_dyn;
  func_sa.prog_bar=true;
  // give energy function
  func_sa.energy=&func5;
  // give random initial guess
  func_sa.state_size=1;
  func_sa.state_curr=new double [func_sa.state_size];
  func_sa.state_curr[0]=(double)rand()/(double)RAND_MAX;
  func_sa.state_curr[0]=func_sa.state_curr[0]*2.0E+1-1.0E+1;
  return;
}

void setup_sa_func6(sa_cont_type &func_sa, int max_step, double t_max, double t_min,
                    std::string cool_opt, bool mon_cool, double smin, double smax, double damping,
                    double resvar, bool damp_dyn){
  // Base information, see main.h for the given parameters.
  func_sa.max_step=max_step;
  func_sa.t_max=t_max;
  func_sa.t_min=t_min;
  func_sa.cool_opt=cool_opt;
  func_sa.mon_cool=mon_cool;
  func_sa.smin=smin;
  func_sa.smax=smax;
  func_sa.damping=damping;
  func_sa.resvar=resvar;
  func_sa.damp_dyn=damp_dyn;
  func_sa.prog_bar=true;
  // give energy function
  func_sa.energy=&func6;
  // give random initial guess
  func_sa.state_size=1;
  func_sa.state_curr=new double [func_sa.state_size];
  func_sa.state_curr[0]=(double)rand()/(double)RAND_MAX;
  func_sa.state_curr[0]=func_sa.state_curr[0]*2.0E+1-1.0E+1;
  return;
}
