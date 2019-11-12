/**
    *@file caracter_t.hpp
    *@version 1.0
    *@date 10/11/2019
    *@author Angel Julián Bolaño Campos
    *@title Gramáticas Regulares y Autómatas Finitos
*/


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

  /**
      *@brief Constructor por defecto de caracter_t
  */
  caracter_t() {}

  /**
      *@brief Destructor de caracter_t
  */
  ~caracter_t() {}

  /**
      *@brief Constructor para la clase caracter_t
      *@param car Caracter para construir el objeto
      *@param pri Prioridad en el orden de operaciones
      *@param tip Tipo de caracter (Operando | Operador )
      *@param ari Aridad en caso de que sea un operador
  */
  caracter_t(char car, unsigned pri, int tip, int ari);

  /**
      *@brief Constructor de copia para caracter
  */
  caracter_t( const caracter_t& rhs);

  /**

  */
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
