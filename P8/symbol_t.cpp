








#include "symbol_t.hpp"

symbol_t::symbol_t(const symbol_t& rhs) {
  this->name_ = rhs.name_;
  this->is_terminal_ = rhs.is_terminal_;
}

symbol_t& symbol_t::operator=(const symbol_t& rhs) {
  this->name_ = rhs.name_;
  this->is_terminal_ = rhs.is_terminal_;
  return *this;
}

bool symbol_t::operator<(const symbol_t& rhs) const {
  return name_ < rhs.name_;
}
