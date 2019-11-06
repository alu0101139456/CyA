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
#include "DFA2dot.hpp"

void help();

int main (int argc, char* argv[]) {

  if (argc > 1) {
    std::string a = argv[1];
    if(a == "--help") {
      help();
    }
    else if(argc == 3) {
      std::cout << "entrando en nda2dfa_t\n";
      nfa2dfa_t A(argv[1], argv[2]);
      std::cout << "entrando en dfa2dot2dot_t\n";
      DFA2dot_t B(A.convert_to_dfa());

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
