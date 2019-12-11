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

std::list<std::pair<int, int>> return_change( int cuantity) {
  std::list<std::pair<int,int>> returncoins;
  std::list<int> coins;
  coins = { 200, 100, 50, 20, 10, 5, 2, 1};
  bool tar = false;
  while (cuantity > 0 && !coins.empty() ) {
    std::cout << "Empieza bucle "<< std::endl; //DEBUG
    std::pair<int,int> aux;
    if(tar) {
      std::cout << "Incrementado la lista de cambio "<< std::endl; //DEBUG
      returncoins.push_back(aux);
      tar = false;
    }
    if (coins.front() <= cuantity) {
      aux = returncoins.back();
      aux.first = coins.back();
      aux.second += 1;
      returncoins.pop_back();
      returncoins.push_back(aux);
      cuantity = cuantity - coins.front();
    } else {
400        coins.pop_front();
        tar = true;
      }
  }

  return returncoins;
}


int main (void) {

  std::list<std::pair<int,int>> returnedcoins;
  float coinIn;
  std::cout << "Introduzca cantidad a devolver\n";
  std::cin >> coinIn;
  int cuantity = std::round(coinIn*100);

  returnedcoins = return_change(cuantity);

  while (!returnedcoins.empty()) {
    int M = returnedcoins.front().first;
    int C = returnedcoins.front().second;
    std::cout << "Monedas de: " << M << " x " << C << "\n";
    returnedcoins.pop_front();

  }



}
