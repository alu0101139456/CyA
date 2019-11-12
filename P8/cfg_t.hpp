








#pragma once
#include <set>
#include <map>
#include <iostream>
#include <fstream>
#include <utility>

#include "cadena_t.hpp"
#include "symbol_t.hpp"
//#include "nfa_t.hpp" falta incluirla en el directorio
struct checker {
  std::pair<bool, int> alpha = std::make_pair(false, 0);
  std::pair<bool, int> symbols = std::make_pair(false, 0);
  bool start=false;
  std::pair<bool, int> productions = std::make_pair(false, 0);
};


typedef std::map<symbol_t, std::set<cadena_t>> produccion_t;

class cfg_t {
 private:
   std::set<symbol_t> no_terminal_;
   std::set<symbol_t> alfabeto_;
   produccion_t producciones_;
   symbol_t arranque_;


 public:
  cfg_t(){}
  ~cfg_t(){}

  cfg_t(std::string FileIn);

  void print();


  //nfa_t convert_to_nfa();
};
