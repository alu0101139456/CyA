/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 7: Construcción de Subconjuntos                                   *
 ****************************************************************************/
//                               estado_t.cpp

#include "estado_t.hpp"

//El constructor genera un id unico por cada valor de string para poder utilizar
//las funciones find() e insert() de la std::set
estado_t::estado_t(unsigned id, std::string name) {
  id_ = 0;
  acept_ = false;
  for(size_t i = 0; i < name.length(); i++)  {
    id_+= 131 * id_ + name[i];
  }
  name_ = name;
}

void estado_t::clean() {
  id_ = 0;
  name_.clear();
  acept_= false;
  arranque = false;
  trans_map aux;
  transiciones_ = aux;
}

std::set<estado_t> estado_t::get_trans_with(char symbol)const {
  std::set<estado_t> tmp;
  if(transiciones_.find(symbol) != transiciones_.end())
    tmp = transiciones_.at(symbol);
  return tmp;
}

void estado_t::insert_tr(char caracter, estado_t& aux) {
  if (transiciones_.find(caracter) == transiciones_.end()){
    std::set<estado_t> new_est;
    new_est.insert(aux);
    transiciones_.insert(std::make_pair(caracter, new_est));
  }
  else {
    std::set<estado_t>& tmp = transiciones_[caracter];
    tmp.insert(aux);
  }
}

void estado_t::insert_e_tr(estado_t aux) {
  e_transiciones_.insert(aux);
}



estado_t::estado_t(const estado_t& rhs) {
  this->id_= rhs.id_;
  this->name_ = rhs.name_;
  this->acept_ = rhs.acept_;
  this->transiciones_ = rhs.transiciones_;
  this->arranque = rhs.arranque;
  this->e_transiciones_ = rhs.e_transiciones_;
}


estado_t& estado_t::operator=(const estado_t& rhs) {
  this->id_ = rhs.id_;
  this->name_ = rhs.name_;
  this->acept_ = rhs.acept_;
  this->transiciones_ = rhs.transiciones_;
  this->arranque = rhs.arranque;
  this->e_transiciones_ = rhs.e_transiciones_;
  return *this;
}
