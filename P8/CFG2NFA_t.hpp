/**
    *@file CFG2NFA_t.hpp
    *@version 1.0
    *@date 10/11/2019
    *@author Angel Julián Bolaño Campos
    *@title Gramáticas Regulares y Autómatas Finitos
*/


#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "cfg_t.hpp"
#include "nfa_t.hpp"

class CFG2NFA_t {
 private:
  cfg_t cfg_;
  nfa_t nfa_;
  std::string out_file_;

 public:

  /**
      *@brief Constructor por defecto de CFG2NFA
  */
  CFG2NFA_t(){}

  /**
      *@brief Constructor de CFG2NFA
      *@param infile Nombre del fichero de entrada con los datos de la gramática
      *@param outfile Nombre del fichero de salida para volcar el nfa
  */
  CFG2NFA_t(std::string infile, std::string outfile);

  /**
      *@brief Destructor de CFG2NFA
  */
  ~CFG2NFA_t(){}

  /**
      *@brief Imprime por pantalla la gramática
  */
  void print_grammar();

  /**
      *@brief Imprime por pantalla el nfa
  */
  void print_autommata();

  /**
      *@brief Conversión de la gramática a nfa
  */
  void convert_to_nfa();

  /**
      *@brief vuelca los datos del nfa en el fichero especificado en el constructor
  */
  void print_nfa_to_file();
};
