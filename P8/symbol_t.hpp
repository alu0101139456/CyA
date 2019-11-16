/**
    *@file symbol_t.hpp
    *@version 1.0
    *@date 10/11/2019
    *@author Angel Julián Bolaño Campos
    *@title Gramáticas Regulares y Autómatas Finitos
*/


#pragma once
#include<iostream>


class symbol_t {
 private:
   char name_;
   bool is_terminal_;

 public:

   /**
      *@brief Constructor por defecto de symbol
   */
   symbol_t(){};

   /**
      *@brief Destructor de symbol
   */
   ~symbol_t() {};

   /**
      *@brief Constructor de copia de symbol
      *@param rhs Right Hand Side Simbolo a copiar
   */
   symbol_t(const symbol_t& rhs);

   /**
      *@brief Constructor de symbol
      *@param name Nombre/caracter del símbolo
      *@param terminal Tipo de símbolo
   */
   symbol_t(char name, bool terminal): name_(name), is_terminal_(terminal){}

   /**
      *@brief Comprobación sobre tipo de simbolo
      *@return Devuelve true si el símbolo es terminal
   */
   bool is_terminal() { return is_terminal_; }

   /**
      *@brief Obtención del caracter que representa el símbolo
      *@return Devuelve el caracter que representa el símbolo
   */
   char get_name() const { return name_; }

   /**
      *@brief Sobrecarga del operador de comparación <
      *@param rhs Right Hand Side Simbolo con el que comparamos
      *@return Devuelve true si this < rhs
   */
   bool operator<(const symbol_t& rhs) const;

   /**
      *@brief Sobrecarga del operador de asignación
      *@param rhs Right Hand Side Simbolo con el que copiaremos
      *@return Devuelve *this
   */
   symbol_t& operator=(const symbol_t& rhs);

   /**
      *@brief Sobrecarga del operador de comparación ==
      *@param rhs Right Hand Side Simbolo con el que comparamos
      *@return Devuelve true si this == rhs
   */
   bool operator==(const symbol_t& rhs) const;

};
