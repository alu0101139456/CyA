/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                           *
 * Asignatura: Computabilidad y Algoritmia                                     *
 * Curso: 2º Ingeniería Informática                                            *
 * Editor: VIM                                                                 *
 * Estilo Google C++ Style Guide                                               *
 * Práctica 5: Expresiones regulares                                           *
 * ****************************************************************************/

#include "../include/caracter_t.hpp"


caracter_t::caracter_t( const caracter_t& rhs) {
  this->caracter_ = rhs.caracter_;
  this->prioridad_= rhs.prioridad_;
  this->tipo_ = rhs.tipo_;
  this->aridad_ = rhs.aridad_;
}

caracter_t::caracter_t( char car, unsigned pri, int tip, int ari):
caracter_(car),
prioridad_(pri),
tipo_(tip),
aridad_(ari)
{}


void caracter_t::set_caracter(char car) {
  caracter_=car;
}

void caracter_t::set_prioridad(unsigned pri) {
  prioridad_=pri;
}

void caracter_t::set_tipo(int tipo) {
  tipo_=tipo;
}

char caracter_t::get_caracter() {
 return caracter_;
}

unsigned caracter_t::get_prioridad() {
 return prioridad_;
}

int caracter_t::get_tipo() {
 return tipo_;
}


bool caracter_t::operator==(const caracter_t& rhs) const  {
  return this->caracter_ == rhs.caracter_;
}

bool caracter_t::operator<(const caracter_t& rhs) const  {
  return this->caracter_ < rhs.caracter_;
}


caracter_t& caracter_t::operator=(const caracter_t& rhs) {
  this->caracter_ = rhs.caracter_;
  this->prioridad_= rhs.prioridad_;
  this->tipo_ = rhs.tipo_;
  this->aridad_ = rhs.aridad_;
  return  *this;
}




