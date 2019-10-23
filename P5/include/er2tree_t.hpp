#pragma once
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 5: Expresiones regulares                                          *
 * **************************************************************************/
//                              er2tree.hpp

#include "alfabeto_t.hpp"
#include "expreg_t.hpp"
#include "tree_t.hpp"

#include <vector>
#include <fstream>
#include <iostream>

class er2tree_t {
 private:
  std::ifstream fileIn_;
  std::ofstream fileOut_;
  std::vector<tree_t> arboles_;
  alfabeto_t alfa_;

 public:
  er2tree_t() {}
  ~er2tree_t() {}
  er2tree_t(std::string filein, std::string fileout);



 private:
  void read_from_file();



};
