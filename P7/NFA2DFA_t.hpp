/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 7: Construcción de Subconjuntos                                   *
 ****************************************************************************/ 
//                                NFA2DFA_T.hpp

#pragma once

#include<iostream>
#include<fstream>
#include "dfa_t.hpp"
#include "nfa_t.hpp"
#include "estado_t.hpp"
:x

class nfa2dfa_t {
 private:



 public:
  void read_file();

 private:
  void read_alpha_from_file();
  void read_states_from_file();
  void read_acept_states_from_file();
  void read_transitions_from_file();
};
