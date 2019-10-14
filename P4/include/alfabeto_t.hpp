
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶¶
 * Autor: Ángel Julián Bolaño Campos                                          *¶
 * Asignatura: Computabilidad y Algoritmia                                    *¶
 * Curso: 2º Ingeniería Informática                                           *¶
 * Editor: VIM                                                                *¶
 * Estilo Google C++ Style Guide                                              *¶
 * Práctica 4: Eliminador de comentarios                                      *
 * **************************************************************************/
//                          alfabeto_t.hpp
#pragma once

#include<iostream>
#include<set>
#include<fstream>
#include<string>


class alfabeto_t {
 private:
  std::set<int> alfa_;

 public:

  alfabeto_t();
  ~alfabeto_t() {}

  std::set<int>::iterator find_symbol(int sym);
  std::set<int>::iterator end();
  bool pertenece( int caracter);

};
