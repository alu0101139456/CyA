/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 7: Construcción de Subconjuntos                                   *
 ****************************************************************************/
//                                nfa_t.hpp
#pragma once
#include<iostream>
#include<set>
#include<vector>
#include<stack>
#include "estado_t.hpp"
#include "conjunto_estado_t.hpp"
#include "dfa_t.hpp"
#include "alfabeto_t.hpp"

const char EPS = '~';

class nfa_t {
 private:
  std::set<estado_t> estados_;
  estado_t arranque_;
  alfabeto_t alpha;
  //TODO: Falta alfabeto
  // std::map<estado_t, std::map<char, std::set<estado_t>>> trans_;
  // std::map<estado_t, std::set<estado_t>> e_trans_;

 public:
  //BUILDERS
  nfa_t() {}
  nfa_t(const nfa_t& rhs);
  ~nfa_t() {}



  //FUNCTIONS
  void insert_estado(estado_t estado);
  std::set<estado_t> e_clausura(const std::set<estado_t>& T);
  void convert_to_dfa();
  void print();
  void print_ini();
  std::set<con_est_t>::iterator pertenece(const con_est_t& a,\
                                          const std::set<con_est_t>&b);


  //SETTERS
  std::set<estado_t>::iterator begin();
  std::set<estado_t>::iterator end();
  std::set<estado_t>::iterator find_estado(std::string& name);
  void update_estado(std::set<estado_t>::iterator& it,const estado_t& nuevo);
  void set_alpha(const alfabeto_t& alfabeto){ alpha = alfabeto;}
  //GETTERS
  unsigned get_n_estados() { return estados_.size(); }
  std::vector<std::string> get_est_acept();
  estado_t get_est_arranque();
  std::string get_est_arranque_p();

  //OPERATORS
  nfa_t& operator=(const nfa_t& rhs);



};
