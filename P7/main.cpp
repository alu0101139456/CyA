/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 7: Construcción de Subconjuntos                                   *
 ****************************************************************************/
//                                main.cpp

#include<iostream>
#include<fstream>
#include "NFA2DFA_t.hpp"

void help();

int main (int argc, char* argv[]) {

  if (argc > 1) {
    std::string a = argv[1];
    if(a == "--help") {
      help();
    }
    else if(argc == 3) {
      nfa2dfa_t(argv[1], argv[2]);
    }
    else std::cout << "Numero de argumentos invalido";
  }
  else {
    std::cout << "Modo de empleo: ./NFA2DFA input.nfa output.dfa\n";
    std::cout << "Pruebe ’NFA2DFA --help’ para más información. \n";
  }
}



void help() {
  system("clear");
  std::ifstream in("help");
  std::string out;
  while(!in.eof()) {
    getline(in, out);
    std::cout << out << std::endl;
  }
  
}
