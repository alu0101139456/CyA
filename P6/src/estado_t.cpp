

#include "../include/estado_t.hpp"

void estado_t::clean() {
  //id_ = 0;
  name_.clear();
  acept_= false;
  arranque = false;
  trans_map aux;
  transiciones_ = aux;
}


estado_t::estado_t( const estado_t& rhs){
  this->id_ = rhs.id_;
  this->name_ = rhs.name_;
  this->acept_ = rhs.acept_;
  this->transiciones_ = rhs.transiciones_;
  this->arranque = rhs.arranque;

}
