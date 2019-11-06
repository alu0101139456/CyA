/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 7: Construcción de Subconjuntos                                   *
 * ***************************************************************************/
//                              dfa_t.hpp
#pragma once

#include<set>
#include<iostream>
#include<fstream>
#include<vector>

#include "estado_t.hpp"

class dfa_t {
 private:
  std::set<estado_t> estados_;

 public:
  dfa_t() {}
  ~dfa_t() {}
  dfa_t( const dfa_t& rhs) { this-> estados_ = rhs.estados_; }

  void insert_estado( estado_t estado);
  void analiza( char caracter);
  std::set<estado_t>::iterator begin();
  std::set<estado_t>::iterator end();
  std::set<estado_t> get_estados();
  std::set<estado_t>::iterator find_estado(std::string& name);
  void update_estado(std::set<estado_t>::iterator& it,const estado_t& nuevo);
  
  unsigned get_size() { return estados_.size(); }
  void print();
  std::vector<std::string> get_est_acept();
  std::string get_est_arranque();

  dfa_t& operator=(const dfa_t& rhs) {
    this->estados_ = rhs.estados_;
    return *this;
  }

};
