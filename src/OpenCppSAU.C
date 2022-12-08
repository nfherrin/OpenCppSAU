// OpenCppSAU is a C++ version of OpenFSAM

#include "OpenCppSAU.h"
#include <iostream>

using namespace std;

// Optimization subroutine for the base class, valid for both types
void sa_type_base::optimize(){
  cout << "This is an indicator that optimize is being reached." << endl;
}