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

#include <map>

typedef std::map<char, unsigned> trans_map;


class estado_t {
 private:
  unsigned id_;
  bool acept_;
  std::map<char, unsigned> transiciones_;

 public:
  estado_t(): id_(0) {}
  ~estado_t() {}

  estado_t(unsigned id, bool acept, std::map<char,unsigned> transiciones):
      id_(id),
      acept_(acept),
      transiciones_(transiciones){}


  unsigned int get_id() const { return id_; }

  bool get_acept() const { return acept_; }

  bool operator<(const estado_t& rhs) const {
    return (this->get_id() < rhs.get_id());}

  const trans_map& get_tran() const {return transiciones_;}

};


