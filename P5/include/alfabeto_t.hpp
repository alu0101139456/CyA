#pragma once
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶¶
 * Autor: Ángel Julián Bolaño Campos                                          *¶
 * Asignatura: Computabilidad y Algoritmia                                    *¶
 * Curso: 2º Ingeniería Informática                                           *¶
 * Editor: VIM                                                                *¶
 * Estilo Google C++ Style Guide                                              *¶
 * Práctica 5: Expresiones regulares                                          *
 * **************************************************************************/
//                          alfabeto_t.hpp

#include<iostream>
#include<set>
#include<fstream>
#include<string>
#include "caracter_t.hpp"

class alfabeto_t {
 private:
  std::set<caracter_t> alfa_;

 public:

  alfabeto_t();
  ~alfabeto_t() {}
  alfabeto_t( const alfabeto_t& rhs);

  std::set<caracter_t>::iterator find_symbol(char sym);
  std::set<caracter_t>::iterator end();
  bool pertenece( caracter_t caracter);
  bool is_in_alphabet(std::string expresion);
  caracter_t find(char sym);

  alfabeto_t& operator=(const alfabeto_t& rhs);

};
