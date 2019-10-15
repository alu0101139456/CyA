/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 2: Análisis de Texto                                              *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include "../include/AnalizerWords_t.hpp"

typedef std::set<std::string> SetStrng;
void help();

int main(int argc, char *argv[]) {
  if ( argc >= 1  && argc <=  3)
    AnalizerWords_t analizer(argv[1], argv[2]);
  else
    help();
}


void help() {
  system("clear");
  std::cout << "\nHELP";
  std::cout << "\nDESCRIPTION     \n";
  std::cout << "analizer [FILE INPUT] [FILE_OUTPUT]     \n";
  std::cout << "\n";
}






