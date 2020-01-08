#include <cstdio>
#include <vector>
#include <random>
#include <iostream>

#include "sorted_vector_t.hpp"

#define LIMIT 999
#define SIZE   80

using namespace std;

bool test(std::vector<int> vt) {
  int i=1;
  std::vector<int> aux;
  while (i != vt.size() )
  {
     aux.push_back( vt[i] - vt[i-1]);
     if( (vt[i] - vt[i-1]) < 0) return false;
     i++;
  }
  cout << aux << endl;
  return true;
}


int main(void)
{
    default_random_engine generator;
    uniform_int_distribution<int> distribution(-LIMIT, LIMIT);
    CyA::sorted_vector_t v;

    for(int i = 0; i < SIZE; i++)
        v.push_back(distribution(generator));
    cout << "\n\nVector desordenado\n\n";
    cout << v << endl;

    v.merge_sort();

    cout << "\n\nVector ordenado \n\n";
    cout << v << endl;
     
    cout << "\n\nVector comprobado \n\n";
    if (test(v)) cout << "Test correcto"<< endl;
    else cout << "Test fallido" << endl;

return 0;
}
