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

  /**
      *@brief Constructor por defecto de la clase cfg
  */
  cfg_t(){}

  /**
      *@brief Destructor de la clase cfg
  */
  ~cfg_t(){}

  /**
      *@brief Constructor de la clase cfg
      *@param FileIn Nombre del fichero de entrada con el que construimos el cfg
  */
  cfg_t(std::string FileIn);

  /**
      *@brief Obtención del conjunto de símbolos del alfabeto
      *@return Conjunto de símbolos que pertenecen al alfabeto
  */
  std::set<symbol_t>& get_alfabeto();

  /**
      *@brief Obtención del conjunto de símbolos no terminales
      *@return Conjunto de símbolos que pertenecen a los no terminales
  */
  std::set<symbol_t>& get_no_terminal();

  /**
      *@brief Obtención de las producciones de la gramática
      *@return Mapa de producciones de la gramática
  */
  produccion_t& get_producciones();

  /**
      *@brief Obtención símbolo de arranque de la gramática
      *@return Símbolo de arranque
  */
  symbol_t& get_arranque();

  /**
      *@brief Impresión de la gramática
  */
  void print();

  /**
      *@brief Conversión de la gramática en NFA
      *@return Copia del NFA Resultante
  */
  nfa_t convert_to_nfa();
};
