/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 5: Expresiones regulares                                          *
 * ****************************************************************************/

#include <iostream>
#include "../include/er2tree_t.hpp"

void help();

int main(int argc, char* argv[] ) {
 switch(argc) {
   case 3: {
      er2tree_t(argv[1], argv[2]);
      break;
    }
   default:
     help();
     break;

 }

}



void help() {
  system("clear");
  std::cout << "Instrucciones de uso\n";
  std::cout << "SYNTAX: \n\n  ER2Tree [fileIN] [fileOUT] \n" << std::endl;
}
