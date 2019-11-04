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
  for(size_t i = 0; i < name.length(); i++)  {
    id_+= 131 * id_+ name[i];
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


void estado_t::insert_tr(std::pair<char,std::string> aux) {
  transiciones_.insert(aux);
}

void estado_t::insert_e_tr(estado_t aux) {
  e_transiciones_.insert(aux);
}

void estado_t::print_trans()const {
 for(auto it = transiciones_.begin(); it != transiciones_.end(); ++it)
 {
   std::cout << name_ << '\n';
   std::cout << "Con: " << it->first << " a " << it->second << '\n' << std::endl;
 }

}


estado_t::estado_t(const estado_t& rhs) {
  this->id_= rhs.id_;
  this->name_ = rhs.name_;
  this->acept_ = rhs.acept_;
  this->transiciones_ =rhs.transiciones_;
  this->arranque = rhs.arranque;
}


estado_t& estado_t::operator=(const estado_t& rhs) {
  this->id_ = rhs.id_;
  this->name_ = rhs.name_;
  this->acept_ = rhs.acept_;
  this->transiciones_ =rhs.transiciones_;
  this->arranque = rhs.arranque;
  return *this;
}
