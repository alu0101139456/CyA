


#include "../include/caracter_t.hpp"


caracter_t::caracter_t( char car, unsigned pri, int tip):
caracter_(car),
prioridad_(pri),
tipo_(tip)
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







