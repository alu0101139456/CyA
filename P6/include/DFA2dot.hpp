/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                           *
 * Asignatura: Computabilidad y Algoritmia                                     *
 * Curso: 2º Ingeniería Informática                                            *
 * Editor: VIM                                                                 *
 * Estilo Google C++ Style Guide                                               *
 * Práctica 6: Automatas Finitos Deterministas                                 *
 * ****************************************************************************/
//                                DFA2dot.hpp
#pragma once

#include "dfa_t.hpp"
#include "estado_t.hpp"
#include "alfabeto_t.hpp"

#include <fstream>
#include <iostream>
#include <set>


class DFA2dot_t {
 private:
  dfa_t dfa_;
  std::ifstream filein_;
  std::ofstream fileout_;


 public:
  DFA2dot_t() {}
  ~DFA2dot_t() {}
  DFA2dot_t(std::string filein, std::string fileout);


 private:
  void read_file();
  void print_dfa();
};
