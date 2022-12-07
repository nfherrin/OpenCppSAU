// Continuous simulated annealing example variables

#ifndef main_h
#define main_h

// Variables for reference values/locations
double minvals[6];
double minlocs[6];

// Variables for simulated annealing options
int max_step=1000;
double t_max=100.0E+0;
double t_min=1.0E-12;
std::string cool_opt="QuadAdd";
bool mon_cool=false;
double smin=-10.0E+0;
double smax=10.0E+0;
double damping=0.0E+0;
double resvar=1.0E+0;
bool damp_dyn=true;

#endif