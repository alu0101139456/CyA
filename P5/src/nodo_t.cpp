

#include "../include/nodo_t.hpp"


nodo_t::nodo_t(caracter_t val):
valor_(val),
n_izq_(nullptr),
n_der_(nullptr)
{}

nodo_t::~nodo_t(){
  delete n_der_;
  delete n_izq_;
  n_der_ = nullptr;
  n_izq_ = nullptr;
}
caracter_t nodo_t::get_val() {
 return valor_;
}

nodo_t* nodo_t::get_n_izq() {
  return n_izq_;
}

nodo_t* nodo_t::get_n_der() {
  return n_der_;
}

void nodo_t::set_valor(caracter_t val) {
  valor_ = val;
}

void nodo_t::set_nodo_izq(nodo_t* n_izq) {
  n_izq_ = n_izq;
}

void nodo_t::set_nodo_der(nodo_t* n_der) {
  n_der_ = n_der;
}

bool nodo_t::get_modo() {
  return nodoHoja_;
}

