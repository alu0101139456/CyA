/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 4: Eliminador de comentarios                                      *
 * ***************************************************************************/
//                              dfa_t.cpp


#include "../include/dfa_t.hpp"




dfa_t::dfa_t(alfabeto_t Al) {
  Al_ = Al;
  //read_file();
}

//void dfa_t::read_file() {
// //char aux;
//  int aux;
//  if(fileIn_.is_open()) {
//    while (!fileIn_.eof()) {
//      aux = fileIn_.get();
//      if ( compara(aux) ) {
//        char a = aux;
//        if (aux == '\n')
//          std::cout << "encontre salto de linea\n";
//          else std::cout << "encontre " << a << " \n";
//      }
//    }
//  }
//}
//
//
//bool dfa_t::compara(int aux) {
//  std::set<int>::iterator it = Al_.find_symbol(aux);
//  if ( it != Al_.end() ) return true;
//      else return false;
//
//}
