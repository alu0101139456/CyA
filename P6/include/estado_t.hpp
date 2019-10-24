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
  unsigned default_;
  bool estado_escritura_;

 public:
  estado_t( unsigned id): id_(id) {}
  estado_t() { id_ = 0;}
  ~estado_t() {}

  estado_t(unsigned id, bool acept, std::map<char,unsigned> transiciones, 
      unsigned default_id, bool escritura):
      id_(id),
      acept_(acept),
      transiciones_(transiciones),
      default_(default_id),
      estado_escritura_(escritura){}

  unsigned get_default() const {return default_; }

  unsigned int get_id() const { return id_; }

  bool get_acept() const { return acept_; }

  bool operator<(const estado_t& rhs) const {
    return (this->get_id() < rhs.get_id());}

  int operator==(const estado_t& rhs) const {
    return (this->get_id() == rhs.get_id()); }

  const trans_map& get_tran() const {return transiciones_;}

  bool estado_escritura() const { return estado_escritura_;}
};


