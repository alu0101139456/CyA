/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 7: Construcción de Subconjuntos                                   *
 ****************************************************************************/ 
//                                nfa_t.hpp
#include<iostream>
#include<set>
#include<vector>
#include<stack>
#include "estado_t.hpp"

const char EPS = '~';

class nfa_t {
 private:
  std::set<estado_t> estados_;

 public:
  //BUILDERS
  nfa_t() {}
  ~nfa_t() {}



  //FUNCTIONS
  void insert_estado(estado_t estado);
  std::set<estado_t> e_clausura(std::set<estado_t> T);
  
  //SETTERS
  std::set<estado_t>::iterator begin();
  std::set<estado_t>::iterator end();
  std::set<estado_t>::iterator find_estado(std::string& name);
  void update_estado(std::set<estado_t>::iterator& it,const estado_t& nuevo);
  
  //GETTERS
  unsigned get_n_estados() { return estados_.size(); }
  std::vector<std::string> get_est_acept();
  long long int get_est_arranque();
  std::string get_est_arranque_p();

};
