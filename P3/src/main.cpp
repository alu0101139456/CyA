/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 3: Calculadora de lenguajes formales                              *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <iostream>
#include "../include/calculadora_t.hpp"
//#include<fstream>


void help () {
  std::cout << "Instrucciones de uso para Calculadora de lenguajes Formales\n";
  std::cout << "\n\n\ncalculate [FILE_IN] [FILE_OUT] [OPERATION]\n";
  std::cout << "\n\n    1  Contatenación ";
  std::cout << "\n\n    2  Union  ";
  std::cout << "\n\n    3  Interseccion  ";
  std::cout << "\n\n    4  Diferencia  ";
  std::cout << "\n\n    5  Sublenguajes  ";
  std::cout << "\n\n    6  Igualdad de Lenguajes  ";
  std::cout << "\n\n    7  Inversa  ";
  std::cout << "\n\n    8  Potencia  ";
  std::cout << "\n\n    9  Cierre Positivo  ";
  std::cout << "\n\n    10 Cierre de Kleen  ";
}


int main ( int argc, char *argv[]) {
  
  switch(argc) {
      case 4: {
          calculadora_t A(argv[1], argv[2], argv[3]);
          break;
              }
      default: help();
  }



}
