

#ifndef main_h
#define main_h

#include <iostream>
#include <string>
#include "OpenCppSAU.h"
#include "travel_sales.h"

using namespace std;

// traveling salesman problem dimensions
int prob_dim=1;

// number of customers
int num_customers=10;

// best from sa and sort
double sort_best;

// Simulated annealing object for the traveling salesman problem
sa_comb_type ts_simanneal;

#endif