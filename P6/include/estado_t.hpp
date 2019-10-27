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

typedef std::map<char, std::string> trans_map;


class estado_t {
 private:
  unsigned id_;
  std::string name_;
  bool acept_;
  trans_map transiciones_;
  bool arranque;

 public:
  estado_t() {}
  ~estado_t() {}

  estado_t(unsigned id, std::string name): id_(id), name_(name) {}

  unsigned int get_id() const { return id_; }
  std::string get_name() const {return name_;}
  bool get_acept() const { return acept_; }

  bool operator<(const estado_t& rhs) const {
    return (this->get_id() < rhs.get_id());}

//  int operator==(const estado_t& rhs) const {
//    return (this->get_id() == rhs.get_id()); }

  int operator==( estado_t& rhs) {
    return (this->get_name() == rhs.get_name()); }

  const trans_map& get_tran() const {return transiciones_;}

  void set_acept(bool aux) { acept_ = aux; }
  void set_trans(trans_map map) { transiciones_ = map; }
  
};


