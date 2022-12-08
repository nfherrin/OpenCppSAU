// types and variables for the OpenCppSAU utility

#ifndef OpenCppSAU_h
#define OpenCppSAU_h

#include <string>

//the base simulated annealing solver type
class sa_type_base{
    public:
        // number of points in a state
        int size_states=0;
        // maximum number of SA iterations
        int max_step=100;
        // total number of steps it took
        int total_steps=0;
        // alpha value for cooling
        double alpha=1.0E-2;
        // maximum temperature
        double t_max=1.0E+2;
        // minimum temperature
        double t_min=0.0E0;
        // best energy
        double e_best=1.0E+307;
        // cooling option
        std::string cool_opt="LinAdd";
        // whether cooling is monotonic or not
        bool mon_cool=true;
        // progress bar
        bool prog_bar=false;
        // the initial temperature to start resetting the current state to the best found state
        //    when this temperature is reached. This temperature is halved every-time it is reached.
        double resvar=0.0E0;
        // Cooling schedule, to be set by the cooling option
        double (*cool)(double tmin, double tmax, double alpha, int k, int n);
        void optimize();
};

#endif