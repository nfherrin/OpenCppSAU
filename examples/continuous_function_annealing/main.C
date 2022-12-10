// Continuous simulated annealing example

#include "main.h"

using namespace std;

double (*eg1_test_pt)(double *vals_to_test);

int main(){

  minvals=new double [6];
  minlocs=new double [6];

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
  setup_sa_func1(func_sa, max_step, t_max, t_min, cool_opt, mon_cool, smin, smax, damping,
                  resvar, damp_dyn);
  cout << func_sa.max_step << endl;
  cout << max_step << endl;
  cout << minlocs[0] << endl;
  cout << func2(&minlocs[1]) << endl;
  eg1_test_pt=&func1;
  cout << eg1_test_pt(minlocs) << endl;
  // func_sa.energy=&func1;
  cout << func_sa.energy(minlocs) << endl;
  func_sa.optimize();

  return 0;
}