


#include<iostream>
#include <set>
#include "estado_t.hpp"


int main(void)
{
  estado_t e1(1,"hola");
  estado_t e2(2,"que");
  estado_t e3(3,"tal");

  std::set<estado_t> aux;
  aux.insert(e1);
  aux.insert(e2);
  aux.insert(e3);
  
  estado_t temp(aux.size(),"tal");

  std::set<estado_t>::iterator it = aux.find(temp);

  std::cout << "Encontré: " << it->get_name() << '\n';

}
