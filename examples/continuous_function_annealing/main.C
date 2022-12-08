// Continuous simulated annealing example

#include <iostream>
#include "main.h"
#include "optimizing_functions.h"
#include "sa_setups.h"
#include "OpenCppSAU.h"

using namespace std;

int main(){

  // Reference minimum point values
  minvals[0]=1.5449192781044832E+01;
  minvals[1]=1.4184540054199392E+01;
  minvals[2]=1.5419753322096613E+01;
  minvals[3]=1.1714693326018384E+01;
  minvals[4]=7.7653742475768439E-01;
  minvals[5]=1.4790147335588884E+01;

  // Reference minimum point locations
  minlocs[0]=-1.1260671421437776E+00;
  minlocs[1]= 2.8556531452530787E+00;
  minlocs[2]= 8.5763080142082426E+00;
  minlocs[3]= 8.9206430998425876E+00;
  minlocs[4]=-8.3519922528629209E+00;
  minlocs[5]=-2.9760703957656585E+00;

  cout << "-----------------------------------function 1-----------------------------------" << endl;
  setup_sa_func1();
  cout << test_sa_obj.state_size << endl;
  test_sa_obj.optimize();

  return 0;
}