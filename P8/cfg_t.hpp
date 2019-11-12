/**
    *@file cfg_t.hpp
    *@version 1.0
    *@date 10/11/2019
    *@author Angel Julián Bolaño Campos
    *@title Gramáticas Regulares y Autómatas Finitos
*/

#pragma once
#include <set>
#include <map>
#include <iostream>
#include <fstream>
#include <utility>

#include "cadena_t.hpp"
#include "symbol_t.hpp"
#include "nfa_t.hpp"
#include "estado_t.hpp"
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

  std::set<symbol_t>& get_alfabeto();
  std::set<symbol_t>& get_no_terminal();
  produccion_t& get_producciones();
  symbol_t& get_arranque();

  void print();


  nfa_t convert_to_nfa();
  void print_nfa();


 private:
   void create_chain(nfa_t& nfa,
                     int nSteps,
                     std::string st_name,
                     std::string cadena,
                     int& count,
                     estado_t& origenAux,
                     std::set<estado_t>::iterator itOrigen
                   );
};
