/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 12: Algoritmos Voraces (Greedy)                                   *
 ****************************************************************************/
//                                main.cpp
#include<iostream>
#include<list>
#include<vector>
#include<utility>
#include<cmath>
#include "dll_t.hpp"
#include "dll_node_t.hpp"

std::list<std::pair<int, int>> return_change( int cuantity) {
  std::list<std::pair<int,int>> returncoins;
  AED::dll_t<AED::dll_node_t<int>> coins;
  coins = { 200, 100, 50, 20, 10, 5, 2, 1};
  int i=0;
  while (cuantity > 0 && i != coins.size() ) {
    if (coins.front() <= cuantity) {
      
    }
  }

  return returncoins;
}

void insert_values(AED::dll_t<AED::dll_node_t<int>>& coins) {
  

}

int main (void) {

  std::list<std::pair<int,int>> returnedcoins;
  float coinIn;
  std::cout << "Introduzca cantidad a devolver\n";
  std::cin >> coinIn;
  int cuantity = std::round(coinIn*100);

  returnedcoins = return_change(cuantity);

  



}
