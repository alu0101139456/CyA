








#include "cadena_t.hpp"

cadena_t::cadena_t(const cadena_t& rhs){
  this->name_ = rhs.name_;
  this->cadena_ =rhs.cadena_;
  this->id_ = rhs.id_;
  this->is_terminal_ = rhs.is_terminal_;
}

void cadena_t::append(symbol_t aux) {
  if (!aux.is_terminal()) {
    is_terminal_ = false;
  }
  id_ += cadena_.size() * 131 + aux.get_name();
  cadena_.push_back(aux);
  name_.push_back(aux.get_name());
}

const std::vector<symbol_t>& cadena_t::get_cadena() const {
  return cadena_;
}
std::string cadena_t::get_name() const {
  return name_;
}

long int cadena_t::get_id() const {
  return id_;
}

bool cadena_t::is_terminal() const {
  return is_terminal_;
}

cadena_t& cadena_t::operator=(const cadena_t& rhs) {
  this->cadena_ = rhs.cadena_;
  this->id_ = rhs.id_;
  this->is_terminal_ = rhs.is_terminal_;
  return *this;
}

bool cadena_t::operator<(const cadena_t& rhs) const {
  return id_ < rhs.id_;
}
