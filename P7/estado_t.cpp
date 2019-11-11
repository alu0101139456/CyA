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
    id_+= 31 * id_ + name[i];
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
  return transiciones_.at(symbol);
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

void estado_t::print_trans() const {
 //for(auto it = transiciones_.begin(); it != transiciones_.end(); ++it)
 //{
 //  std::cout << name_ << '\n';
 //  std::cout << "Con: " << it->first << " a " << it->second << '\n' << std::endl;
 //}

}

void estado_t::print(std::set<estado_t>& aux)const {
  if(aux.find(*this) == aux.end() ) { 
    aux.insert(*this);
    std::cout << "Estado: "<< get_name() << '\n';
    for(auto it = transiciones_.begin(); it != transiciones_.end(); it++ ){
      std::cout << "con: " << it->first << " a: ";
      for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++){
        std::cout << it2->get_name() << ',';
      }
      std::cout << '\n';
    }
    for(auto it = e_transiciones_.begin(); it != e_transiciones_.end(); ++it){
      std::cout << "con: ~" << " a: " << it->get_name();
    }
    std::cout << '\n';
    for(auto it = transiciones_.begin(); it != transiciones_.end(); it++ ){
      for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++){
        it2->print(aux);
      }
    }
    for(auto it = e_transiciones_.begin(); it != e_transiciones_.end(); ++it){
      it->print(aux);
    }
  }
}



estado_t::estado_t(const estado_t& rhs) {
  this->id_= rhs.id_;
  this->name_ = rhs.name_;
  this->acept_ = rhs.acept_;
  this->transiciones_ = rhs.transiciones_;
  this->arranque = rhs.arranque;
}


estado_t& estado_t::operator=(const estado_t& rhs) {
  this->id_ = rhs.id_;
  this->name_ = rhs.name_;
  this->acept_ = rhs.acept_;
  this->transiciones_ = rhs.transiciones_;
  this->arranque = rhs.arranque;
  return *this;
}
