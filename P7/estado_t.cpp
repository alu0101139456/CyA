

#include "estado_t.hpp"

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
