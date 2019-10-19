#pragma once

#include<iostream>


enum tipo { OPERANDO, OPERADOR };

class caracter_t {
 private:
  char caracter_;
  unsigned prioridad_;
  int tipo_;
 
 public:
  caracter_t() {}
  ~caracter_t() {}
  caracter_t(char car, unsigned pri, int tip);
  void set_caracter( char car);
  void set_prioridad(unsigned pri);
  void set_tipo(int tipo);

  char get_caracter();
  unsigned get_prioridad();
  int get_tipo();

};
