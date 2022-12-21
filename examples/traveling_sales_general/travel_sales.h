


#ifndef travel_sales_h
#define travel_sales_h

#include <math.h>
#include "OpenCppSAU.h"

void ts_init(int num_customers, int prob_dim, double &sort_best);

void bubble_sort(int * a);

double path_len(int * a);

double dist(double *loc1, double *loc2);

void setup_ts_sa(sa_comb_type &this_sa);

#endif