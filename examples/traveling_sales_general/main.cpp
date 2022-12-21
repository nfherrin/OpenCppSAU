// Simulated annealing solution to the traveling salesman problem.

#include "main.h"

using namespace std;

int  main(int argc, char **argv){

  //get command line arguments if given
  if(argv[1] != NULL)prob_dim=stoi(argv[1]);
  if(argv[1] != NULL && argv[2] != NULL)num_customers=stoi(argv[2]);

  //setup the traveling salesman problem
  sort_best=0.0;
  ts_init(num_customers, prob_dim, sort_best);

  //sets up the simulated annealing for the traveling salesman problem
  setup_ts_sa(ts_simanneal);

  cout << "----------------------------------------------------------------------------------" << endl;
  cout << "                     performing simulated annealing" << endl;
  cout << "----------------------------------------------------------------------------------" << endl;
  ts_simanneal.optimize(ts_simanneal);
  cout << "final length: " << ts_simanneal.e_best << endl;
  cout << "number of steps: " << ts_simanneal.total_steps*1.0 << endl;

  if(sort_best >= 1.0E-10)cout << "Error: " << abs(sort_best-ts_simanneal.e_best)/sort_best << endl;

  return 0;
}