/**
    *@file conjunto_estado_t.hpp
    *@version 1.0
    *@date 10/11/2019
    *@author Angel Julián Bolaño Campos
    *@title Gramáticas Regulares y Autómatas Finitos
*/

#pragma once

#include<set>
#include "estado_t.hpp"
#include<iostream>

class con_est_t {
 private:
  std::set<estado_t> conjuntos_;
  std::string name_;
  long long int id_;

 public:
  con_est_t() {}
  con_est_t(std::string name, std::set<estado_t> aux);
  ~con_est_t() {}
  con_est_t( const con_est_t& rhs);

  std::set<estado_t> move( const char aux) const;

  std::string get_name() const{return name_;}

  int operator<(const con_est_t& rhs) const {
    return( this->id_ < rhs.id_);}

  con_est_t& operator=( const con_est_t& rhs);

  bool operator==(const con_est_t& rhs) const {
    return (this->conjuntos_ == rhs.conjuntos_);}

};
