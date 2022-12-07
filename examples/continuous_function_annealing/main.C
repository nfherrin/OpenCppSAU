// Continuous simulated annealing example

#include <iostream>
#include "main.h"
#include "optimizing_functions.h"

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

  cout << cool_opt << endl;

  cout << func1(minlocs[0]) << endl;
  cout << func2(minlocs[1]) << endl;
  cout << func3(minlocs[2]) << endl;
  cout << func4(minlocs[3]) << endl;
  cout << func5(minlocs[4]) << endl;
  cout << func6(minlocs[5]) << endl;

  return 0;
}