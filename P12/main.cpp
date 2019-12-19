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
#include<string>

std::list<std::pair<int, int>> return_change( int cuantity) {
  std::list<std::pair<int,int>> returncoins;
  std::list<int> coins;
  coins = { 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
  std::pair<int,int> aux, temp;
  temp.first = 200;
  temp.second = 0;
  returncoins.push_back(temp);
  while (cuantity > 0 && !coins.empty() ) {
      if (coins.front() <= cuantity) {
        aux = returncoins.back();
        aux.first = coins.front();
        aux.second += 1;
        returncoins.pop_back();
        returncoins.push_back(aux);
        cuantity = cuantity - coins.front();
        } 
        else { 
          coins.pop_front();
          std::pair<int,int> a;
          a.first = coins.front();
          a.second = 0;
          returncoins.push_back(a);
      }      
  }
  if ( !coins.empty() && cuantity > 0)
        std::cerr << "No es posible devolver el cambio" << std::endl;
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
    std::string final;
    if (M >= 500) {
        M = M / 100;
        final = "Billete de " + std::to_string(M) + "€";
    }
    else if(M >= 100) {
            M = M / 100;
            final = "Monedas de " + std::to_string(M) + "€";
        }
        else final = "Monedas de " + std::to_string(M) + "¢";
    
    int C = returnedcoins.front().second;
    if(returnedcoins.front().second != 0) {
        std::cout << final << " x " << C << "\n";

    }
    returnedcoins.pop_front();

  }
}