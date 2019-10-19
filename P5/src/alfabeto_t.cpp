
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
  getline(alfaFile, aux);
//  caracter_t(char car, unsigned pri, int tip, int ari)
  for(unsigned i=0; i<aux.length(); i++) {
    alfa_.insert(caracter_t(aux[i], 0, OPERANDO, 0));
  }
  for(int i=0; i<2; i++) {
    getline(alfaFile, aux);
    for( unsigned j=0; j<aux.size(); j+=2) {
       alfa_.insert(caracter_t(aux[j], aux[j+1], OPERADOR, i+1));
    }
  }
}

bool alfabeto_t::pertenece(caracter_t caracter) {
  std::set<caracter_t>::iterator it = alfa_.find(caracter);
  if (it != alfa_.end()) return true;
  else return false;
}


std::set<caracter_t>::iterator alfabeto_t::find_symbol(char sym) {
  caracter_t aux(sym, 0, 0, 0);
  return alfa_.find(aux);
}

std::set<caracter_t>::iterator alfabeto_t::end() {
  return alfa_.end();
}
