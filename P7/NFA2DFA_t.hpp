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
#include "conjunto_estado_t.hpp"

typedef std::set<con_est_t> conjunto;

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
   alfabeto_t alpha;
   

 public:
  nfa2dfa_t(std::string filein, std::string fileout);
  dfa_t convert_to_dfa();
  void read_file();
  std::set<con_est_t>::iterator pertenece(const con_est_t& a,
                                          const std::set<con_est_t>& b);

 private:
  
  void read_alpha_from_file(std::string& word);
  void read_states_from_file(std::string& word);
  void read_start_state_from_file(std::string& word);
  void read_acept_states_from_file(std::string& word);
  void read_transitions_from_file(std::string& word);
};




