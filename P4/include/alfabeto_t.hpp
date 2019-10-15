
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
  std::set<char> alfa_;

 public:

  alfabeto_t();
  ~alfabeto_t() {}

  std::set<char>::iterator find_symbol(char sym);
  std::set<char>::iterator end();
  bool pertenece( char caracter);

};
