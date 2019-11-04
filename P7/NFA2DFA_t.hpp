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
#include "alfabeto_t.hpp"

typedef std::set<estado_t> conjunto;

struct checker {
  bool alpha=false;
  bool states=false;
  bool start=false;
  bool a_state=false;
  bool transitions=false;
};


class nfa2dfa_t {
 private:
   std::ifstream FileIn_;
   std::ofstream FileOut_;
   dfa_t Dfa_;
   nfa_t Nfa_;
   checker reader;
   

 public:
  nfa2dfa_t(std::string filein, std::string fileout);
  void convert_to_dfa(nfa_t temp);
  void read_file();

 private:
  
  void read_alpha_from_file(std::string& word);
  void read_states_from_file(std::string& word);
  void read_start_state_from_file(std::string& word);
  void read_acept_states_from_file(std::string& word);
  void read_transitions_from_file(std::string& word);
};




