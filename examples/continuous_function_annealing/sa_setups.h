// Optimizing functions header


#ifndef sa_setups_h
#define sa_setups_h

#include <math.h>
#include <string>
#include "OpenCppSAU.h"
#include "optimizing_functions.h"
#include <ctime>

void  setup_sa_func1(sa_cont_type &func_sa, int max_step, double t_max, double t_min,
                        std::string cool_opt, bool mon_cool, double smin, double smax,
                        double damping, double resvar, bool damp_dyn);
void  setup_sa_func2();
void  setup_sa_func3();
void  setup_sa_func4();
void  setup_sa_func5();
void  setup_sa_func6();

#endif