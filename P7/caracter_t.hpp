/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                           *
 * Asignatura: Computabilidad y Algoritmia                                     *
 * Curso: 2º Ingeniería Informática                                            *
 * Editor: VIM                                                                 *
 * Estilo Google C++ Style Guide                                               *
 * Práctica 7: Construcción de Subconjuntos                                    *
 * ****************************************************************************/
//                            caracter_t.hpp


#pragma once

#include<iostream>


enum tipo { OPERANDO, OPERADOR };
enum aridad { UNARIO=1, BINARIO=2 };

class caracter_t {
 private:
  char caracter_;
  unsigned prioridad_;
  int tipo_;
  int aridad_;
 
 public:
  caracter_t() {}
  ~caracter_t() {}
  caracter_t(char car, unsigned pri, int tip, int ari);
  caracter_t( const caracter_t& rhs);
  void set_caracter( char car);
  void set_prioridad(unsigned pri);
  void set_tipo(int tipo);

  int get_ari() { return aridad_; }
  char get_caracter() const;
  unsigned get_prioridad();
  int get_tipo();

  bool is_operando();
  bool is_a_operando();
  bool is_operador();
  bool is_ParAb();
  bool is_ParCe();
  bool operator==(const caracter_t& rhs) const;
  bool operator<(const caracter_t& rhs) const;
  caracter_t& operator=(const caracter_t& rhs);

};
