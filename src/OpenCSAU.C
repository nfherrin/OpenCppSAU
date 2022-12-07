// OpenCSAM is a C++ version of OpenFSAM

#include <iostream>

using namespace std;

int i;

int main() {
    std::cout << "Hello World!" << endl << endl;
    std::cout << "2 fast 2 World!" << endl << endl;
    i=0;
    while(i < 22){
      i++;
      std::cout << i << ' ' << true << endl;
    }
    return 0;
}