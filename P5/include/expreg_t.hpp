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
#include <vector>

enum tipo_exp { INFIJA, POSFIJA, PREFIJA};

class expreg_t {
 private:
  alfabeto_t alfa_;
  unsigned formato_;
  std::string expre_;
  std::string ex_pf_;
  std::stack<caracter_t> pila_;
  std::vector<caracter_t> v_expresion_;
  std::vector<caracter_t> v_posfija_;
  std::vector<caracter_t> v_sufija_;

 public:
  expreg_t() {}
  ~expreg_t() {}
  expreg_t(std::string expresion, alfabeto_t alfa, unsigned formato);
  //sobrecargar operador de salida
  expreg_t(const expreg_t& rhs);
  std::string convert_to_posfija();
  expreg_t& operator=(const expreg_t& rhs);
  std::vector<caracter_t> get_posfija();

  void set_vector_sufijo(std::vector<caracter_t> aux);
  void set_vector_posfijo(std::vector<caracter_t> aux);
  void set_vector_infijo(std::vector<caracter_t> aux);



 private:
  bool is_in_alphabet();
  std::string convert();
  void check(std::string& ex_pf, caracter_t& aux);



};
