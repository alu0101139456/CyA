/* ****************************************************************************
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 6: Automatas Finitos Deterministas                                  *
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
  bool arranque=false;;

 public:
  estado_t() {}
  ~estado_t() {}
  estado_t(unsigned id, std::string name):
    id_(id),
    name_(name)
  {}

    estado_t(unsigned id, std::string name, bool acpt, trans_map tr, bool arr):
    id_(id),
    name_(name),
    acept_(acpt),
    transiciones_(tr),
    arranque(arr){}

  void clean();

  //GETTER
  unsigned int get_id() const { return id_; }
  std::string get_name() const {return name_;}
  bool get_acept() const { return acept_; }
  int is_arranque() const { return arranque; }
  const trans_map& get_tran() const {return transiciones_;}


  //SETTER
  void set_acept(bool aux) { acept_ = aux; }
  void set_trans(trans_map map) { transiciones_ = map; }
  void set_arranque(bool aux) { arranque = aux; }
  void set_id(unsigned aux) { id_ = aux; }


  //OPERATORS
  bool operator<(const estado_t& rhs) const {
    return (this->get_id() < rhs.get_id());}
  
  int operator==(const estado_t& rhs) const {
    return (this->get_name() == rhs.get_name()); }
};


