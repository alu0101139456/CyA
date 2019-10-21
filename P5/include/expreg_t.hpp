/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶¶
 * Autor: Ángel Julián Bolaño Campos                                          *¶
 * Asignatura: Computabilidad y Algoritmia                                    *¶
 * Curso: 2º Ingeniería Informática                                           *¶
 * Editor: VIM                                                                *¶
 * Estilo Google C++ Style Guide                                              *¶
 * Práctica 5: Expresiones regulares                                          *
 * ****************************************************************************/
//                                EXPREG_T.HPP
#pragma once

#include<iostream>
#include "caracter_t.hpp"
#include "alfabeto_t.hpp"
#include <fstream>
#include <string>
#include <set>
#include <stack>


enum tipo_exp { INFIJA, POSFIJA, PREFIJA};

class expreg_t {
 private:
  alfabeto_t alfa_;
  unsigned formato_;
  std::string expre_;

 public:
  expreg_t() {}
  ~expreg_t() {}
  expreg_t( std::string expresion, alfabeto_t alfa, unsigned formato);
  //sobrecargar operador de salida

  expreg_t convert_to_posfija(unsigned formato);

 private:
  bool is_in_alphabet();



};
