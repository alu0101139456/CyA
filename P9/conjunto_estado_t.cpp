

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

std::set<estado_t> con_est_t::move(const char aux) const{
  std::set<estado_t> temp;
  std::cout << "Moving\n{";
  for(auto it = conjuntos_.begin(); it != conjuntos_.end(); ++it) {
    std::set<estado_t> destinos = it->get_trans_with(aux);
    for (auto it2 = destinos.begin(); it2 != destinos.end(); ++it2)
      std::cout << it2->get_name() << ',';
    if(!destinos.empty()) temp.insert(destinos.begin(), destinos.end());
  }
  std::cout << "}\nFinished the move\n";
  return temp;
}



con_est_t& con_est_t::operator=(const con_est_t& rhs) {
  this->conjuntos_  = rhs.conjuntos_;
  this->name_       = rhs.name_;
  this->id_         = rhs.id_;
  return *this;

}
