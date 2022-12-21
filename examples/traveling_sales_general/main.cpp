// Simulated annealing solution to the traveling salesman problem.

#include "main.h"

using namespace std;

int  main(int argc, char **argv){
  int i;

  if(argv[1] != NULL)prob_dim=stoi(argv[1]);
  if(argv[1] != NULL && argv[2] != NULL)num_customers=stoi(argv[2]);

  ts_init(num_customers, prob_dim);

  //sets up the simulated annealing for the traveling salesman problem
  setup_ts_sa(ts_simanneal);

  cout << "----------------------------------------------------------------------------------" << endl;
  cout << "                     performing simulated annealing" << endl;
  cout << "----------------------------------------------------------------------------------" << endl;
  for(i=0; i<num_customers; i++){
    cout << ts_simanneal.state_curr[i] << endl;
  }
  ts_simanneal.optimize(ts_simanneal);
  cout << "final length: " << ts_simanneal.e_best << endl;
  cout << "number of steps: " << ts_simanneal.total_steps*1.0 << endl;
  // sa_best=ts_simanneal%e_best

  // IF(sort_best .GT. 1.0E-10)WRITE(*,'(A,ES16.8)')'Error: ',ABS(sort_best-sa_best)/sort_best

  return 0;
}