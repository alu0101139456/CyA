/* ****************************************************************************
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 4: Eliminador de comentarios                                      *
 * ****************************************************************************/
//                            estado_t.hpp

#pragma once
#include <iostream>
#include <map>
#include "alfabeto_t.hpp"

class estado_t {
 private:
  unsigned id_;
  bool acept_;

 public:
  estado_t() {}
  ~estado() {}

  estado_t(unsigned id, bool acept, std::map<char,unsigned> transiciones):
      id_(id),
      acept_(acept),
      transiciones_(transiciones){}


  unsigned int get_id();
  bool get_acept();
};


