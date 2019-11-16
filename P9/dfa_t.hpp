/**
    *@file dfa_t.hpp
    *@version 1.0
    *@date 10/11/2019
    *@author Angel Julián Bolaño Campos
    *@title Gramáticas Regulares y Autómatas Finitos
*/


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
  std::vector<std::string> get_est_acept();
  std::string get_est_arranque();

  dfa_t& operator=(const dfa_t& rhs) {
    this->estados_ = rhs.estados_;
    return *this;
  }

  void print();

};
