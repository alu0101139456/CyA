/**
    *@file estado_t.hpp
    *@version 1.0
    *@date 10/11/2019
    *@author Angel Julián Bolaño Campos
    *@title Gramáticas Regulares y Autómatas Finitos
*/

#pragma once
#include<iostream>
#include <map>
#include<set>
class estado_t;
typedef std::map<char, std::set<estado_t>> trans_map;


class estado_t {
 private:
  long long int id_;
  std::string name_;
  bool acept_;
  trans_map transiciones_;
  std::set<estado_t> e_transiciones_;
  bool arranque=false;



 public:
  estado_t() {}
  ~estado_t() {}
  estado_t(std::string name): name_(name) {
    id_ = 0;
    acept_ = false;
    for (int i = 0; i < name.size(); ++i)
      id_ += 131*id_ + name[i];

  }
  estado_t(unsigned id, std::string name); //:
  estado_t(const estado_t&);
  estado_t(unsigned id, std::string name, bool acpt, trans_map tr, bool arr):
    id_(id),
    name_(name),
    acept_(acpt),
    transiciones_(tr),
    arranque(arr){}

  void print(std::set<estado_t>& aux)const;
  void insert_e_tr(estado_t aux);
  void clean();
  void insert_tr (char caracter, estado_t& aux);
  void print_trans()const;

  //GETTER
  long long int get_id() const { return id_; }
  std::string get_name() const {return name_;}
  bool get_acept() const { return acept_; }
  int is_arranque() const { return arranque; }
  const trans_map& get_tran() const {return transiciones_;}
  int get_n_trans()const { return transiciones_.size(); }
  int get_n_e_trans() const {return e_transiciones_.size();}
  std::set<estado_t>::iterator get_eps_begin() const {return e_transiciones_.begin();}
  std::set<estado_t>::iterator get_eps_end() const { return e_transiciones_.end(); }
  std::set<estado_t> get_trans_with( char symbol) const;

  //SETTER
  void set_acept(bool aux) { acept_ = aux; }
  void set_trans(trans_map map) { transiciones_ = map; }
  void set_arranque(bool aux) { arranque = aux; }
  void set_id(unsigned aux) { id_ = aux; }
  void set_name(std::string aux) { name_ = aux; }

  //OPERATORS
  bool operator<(const estado_t& rhs) const {
    return (this->get_id() < rhs.get_id());}

  bool operator==(const estado_t& rhs) const {
    return (this->get_name() == rhs.get_name()); }

  estado_t& operator=(const estado_t& rhs);
};
