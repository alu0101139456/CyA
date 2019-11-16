/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 8: Grmáticas regulares y Autómatas finitos                        *
 ****************************************************************************/
//                                main.cpp
#include<iostream>
#include<fstream>
#include "CFG2NFA_t.hpp"

void help();

int main (int argc, char* argv[]) {

  if (argc > 1) {
    std::string a = argv[1];
    if(a == "--help") {
      help();
    }
    else if(argc == 3) {
      CFG2NFA_t cfg_to_nfa(argv[1], argv[2]);
      cfg_to_nfa.print_grammar();

    }
    else std::cout << "Numero de argumentos invalido";
  }
  else {
    std::cout << "Modo de empleo: ./CFG2NFA input.nfa output.dfa\n";
    std::cout << "Pruebe ’CFG2NFA --help’ para más información. \n";
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
