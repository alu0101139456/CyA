
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo oogle C++ Style Guide                                              *
 * Práctica 4: Eliminador de comentarios                                      *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
//                          alfabeto_t.cpp


#include "../include/alfabeto_t.hpp"


alfabeto_t::alfabeto_t () {
  std::string aux;
  std::ifstream alfaFile("alfabeto.txt");
    while(std::getline(alfaFile, aux) ) {
      alfa_.insert(std::stoi(aux));
    }
}


bool alfabeto_t::pertenece(int caracter) {
  std::set<int>::iterator it = alfa_.find(caracter);
  if (it != alfa_.end()) return true;
  else return false;
}

std::set<int>::iterator alfabeto_t::find_symbol(int sym) {
  return alfa_.find(sym);
}

std::set<int>::iterator alfabeto_t::end() {
  return alfa_.end();
}
