// The functions that the simulated annealing calculation will optimize over.

#include "optimizing_functions.h"

double func1(double x){
  return 10.0*sin(x)-0.05*(x+2.0)+pow(x-1.0,2)+20.0;
}

double func2(double x){
  return 1.78E-6*pow(x,8)+1.86E-5*pow(x,7)-3.75E-4*pow(x,6)-3.61E-3*pow(x,5)+2.55E-2*pow(x,4)
          +2.06E-1*pow(x,3)-4.85E-1*pow(x,2)-3.11E0*x+1.38E0+20.E0;
}

double func3(double x){
  return 1.11E-6*pow(x,8)+7.7E-6*pow(x,7)-1.32E-4*pow(x,6)-1.35E-3*pow(x,5)+3.59E-3*pow(x,4)
          +6.48E-2*pow(x,3)-6.49E-2*pow(x,2)-7.32E-1*x+2.57E0+20.E0;
}

double func4(double x){
  return 3.52E-6*pow(x,8)+1.2E-5*pow(x,7)-6.26E-4*pow(x,6)-1.99E-3*pow(x,5)+3.31E-2*pow(x,4)
          +9.51E-2*pow(x,3)-4.89E-1*pow(x,2)-1.7E0*x+1.45E0+20.E0;
}

double func5(double x){
  return 4.0E-6*pow(x,8)-1.0E-5*pow(x,7)-6.0E-4*pow(x,6)+2.0E-3*pow(x,5)+3.0E-2*pow(x,4)
          -1.0E-1*pow(x,3)-5.0E-1*pow(x,2)+2.0E0*x-10.0E0+20.E0;
}

double func6(double x){
  return 1.57E-6*pow(x,8)+3.89E-6*pow(x,7)-2.8E-4*pow(x,6)-4.28E-4*pow(x,5)+1.39E-2*pow(x,4)
          -4.68E-3*pow(x,3)-7.05E-2*pow(x,2)+9.53E-1*x-2.87E0+20.E0;
}
