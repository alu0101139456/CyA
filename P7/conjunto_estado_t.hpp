
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

  std::set<estado_t> move( const char aux);


};
