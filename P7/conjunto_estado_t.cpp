

#include "conjunto_estado_t.hpp"


con_est_t::con_est_t( std::string name, std::set<estado_t> aux ) {
  name_ = name;
  conjuntos_ = aux;
  id_ = 0;
  for(size_t i = 0; i < name.size() ; i++)
    id_ += 131*id_ + name[i] ;

}

con_est_t::con_est_t( const con_est_t& rhs) {
  this->conjuntos_ = rhs.conjuntos_;
  this->name_ = rhs.name_;
  this->id_ = rhs.id_;
}

std::set<estado_t> con_est_t::move(const char aux) {
  std::set<estado_t> temp;
  for(auto it = conjuntos_.begin(); it != conjuntos_.end(); ++it) {
  
  }

}

