// Continuous simulated annealing example

#include "main.h"

using namespace std;

int main(){

  srand(static_cast<unsigned int>(time(nullptr)));

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
  func_sa.optimize(func_sa);
  cout.precision(4);
  cout << scientific;
  cout << "       min_erg     min_loc" << endl;
  cout << "ref: " << minvals[0] << " " << minlocs[0] << endl;;
  cout << "SA:  " << func_sa.e_best << " " << func_sa.state_best[0] << endl;
  cout << "min_erg_err min_loc_err  num_steps" << endl;
  cout << abs(minvals[0]-func_sa.e_best)/abs(minvals[0]) << "  " << abs(minlocs[0]-func_sa.state_best[0])/abs(minlocs[0]) << "     " << func_sa.total_steps << endl;
  cout << endl;
  func_sa.clear(func_sa);

  cout << "-----------------------------------function 2-----------------------------------" << endl;
  setup_sa_func2(func_sa, max_step, t_max, t_min, cool_opt, mon_cool, smin, smax, damping,
                  resvar, damp_dyn);
  func_sa.optimize(func_sa);
  cout.precision(4);
  cout << scientific;
  cout << "       min_erg     min_loc" << endl;
  cout << "ref: " << minvals[1] << " " << minlocs[1] << endl;;
  cout << "SA:  " << func_sa.e_best << " " << func_sa.state_best[0] << endl;
  cout << "min_erg_err min_loc_err  num_steps" << endl;
  cout << abs(minvals[1]-func_sa.e_best)/abs(minvals[1]) << "  " << abs(minlocs[1]-func_sa.state_best[0])/abs(minlocs[1]) << "     " << func_sa.total_steps << endl;
  cout << endl;
  func_sa.clear(func_sa);

  cout << "-----------------------------------function 3-----------------------------------" << endl;
  setup_sa_func3(func_sa, max_step, t_max, t_min, cool_opt, mon_cool, smin, smax, damping,
                  resvar, damp_dyn);
  func_sa.optimize(func_sa);
  cout.precision(4);
  cout << scientific;
  cout << "       min_erg     min_loc" << endl;
  cout << "ref: " << minvals[2] << " " << minlocs[2] << endl;;
  cout << "SA:  " << func_sa.e_best << " " << func_sa.state_best[0] << endl;
  cout << "min_erg_err min_loc_err  num_steps" << endl;
  cout << abs(minvals[2]-func_sa.e_best)/abs(minvals[2]) << "  " << abs(minlocs[2]-func_sa.state_best[0])/abs(minlocs[2]) << "     " << func_sa.total_steps << endl;
  cout << endl;
  func_sa.clear(func_sa);

  cout << "-----------------------------------function 4-----------------------------------" << endl;
  setup_sa_func4(func_sa, max_step, t_max, t_min, cool_opt, mon_cool, smin, smax, damping,
                  resvar, damp_dyn);
  func_sa.optimize(func_sa);
  cout.precision(4);
  cout << scientific;
  cout << "       min_erg     min_loc" << endl;
  cout << "ref: " << minvals[3] << " " << minlocs[3] << endl;;
  cout << "SA:  " << func_sa.e_best << " " << func_sa.state_best[0] << endl;
  cout << "min_erg_err min_loc_err  num_steps" << endl;
  cout << abs(minvals[3]-func_sa.e_best)/abs(minvals[3]) << "  " << abs(minlocs[3]-func_sa.state_best[0])/abs(minlocs[3]) << "     " << func_sa.total_steps << endl;
  cout << endl;
  func_sa.clear(func_sa);

  cout << "-----------------------------------function 5-----------------------------------" << endl;
  setup_sa_func5(func_sa, max_step, t_max, t_min, cool_opt, mon_cool, smin, smax, damping,
                  resvar, damp_dyn);
  func_sa.optimize(func_sa);
  cout.precision(4);
  cout << scientific;
  cout << "       min_erg     min_loc" << endl;
  cout << "ref: " << minvals[4] << " " << minlocs[4] << endl;;
  cout << "SA:  " << func_sa.e_best << " " << func_sa.state_best[0] << endl;
  cout << "min_erg_err min_loc_err  num_steps" << endl;
  cout << abs(minvals[4]-func_sa.e_best)/abs(minvals[4]) << "  " << abs(minlocs[4]-func_sa.state_best[0])/abs(minlocs[4]) << "     " << func_sa.total_steps << endl;
  cout << endl;
  func_sa.clear(func_sa);

  cout << "-----------------------------------function 6-----------------------------------" << endl;
  setup_sa_func6(func_sa, max_step, t_max, t_min, cool_opt, mon_cool, smin, smax, damping,
                  resvar, damp_dyn);
  func_sa.optimize(func_sa);
  cout.precision(4);
  cout << scientific;
  cout << "       min_erg     min_loc" << endl;
  cout << "ref: " << minvals[5] << " " << minlocs[5] << endl;;
  cout << "SA:  " << func_sa.e_best << " " << func_sa.state_best[0] << endl;
  cout << "min_erg_err min_loc_err  num_steps" << endl;
  cout << abs(minvals[5]-func_sa.e_best)/abs(minvals[5]) << "  " << abs(minlocs[5]-func_sa.state_best[0])/abs(minlocs[5]) << "     " << func_sa.total_steps << endl;
  cout << endl;
  func_sa.clear(func_sa);

  return 0;
}