/**
    *@file alfabeto_t.hpp
    *@version 1.0
    *@date 10/11/2019
    *@author Angel Julián Bolaño Campos
    *@title Gramáticas Regulares y Autómatas Finitos
*/

#pragma once

#include<iostream>
#include<set>
#include<fstream>
#include<string>
#include "caracter_t.hpp"

class alfabeto_t {
 private:
  std::set<caracter_t> alfa_;

 public:
  /**
      *@brief Constructor por defecto de alfabeto.
  */
  alfabeto_t();

  /**
      *@brief Destructor de alfabeto.
  */
  ~alfabeto_t() {}

  /**
      *@brief Constructor de copia de alfabeto.
      *@param rhs Right Hand Side alfabeto a copiar.
  */
  alfabeto_t( const alfabeto_t& rhs);

  /**
      *@brief Inserta un nuevo símbolo en el alfabeto.
      *@param symbol Simbolo a insertar en el alfabeto.
  */
  void insert_symbol( char symbol);

  /**
      *@brief Lee el alfabeto desde un fichero predeterminado.
  */
  void insert_from_file();

  /**
      *@brief Busca un símbolo en el alfabeto
      *@param sym Símbolo a buscar en el alfabeto
      *@return devuelve un iterador apuntando al elemento, o a end() si no lo encuentra
  */
  std::set<caracter_t>::iterator find_symbol(char sym);

  /**
      *@brief Comprueba la pertenencia de un caracter en el alfabeto
      *@param caracter Caracter a comprobar
      *@return Devuelve true en caso de pertenecer, y false en otro caso
  */
  bool pertenece( caracter_t caracter);

  /**
      *@brief Comprueba que todos los símbolos de una cadena están en el alfabeto
      *@param expresion Cadena a comprobar
      *@return Devuelve true si se contiene en el alfabeto yfalse en otro caso
  */
  bool is_in_alphabet(std::string expresion);

  /**
      *@brief Busca un caracter en el alfabeto
      *@param sym símbolo a buscar en alfabeto
      *@return Devuelve una copia del caracter buscado
  */
  caracter_t find(char sym);

  /**
      *@brief Sobrecarga del operador de asignación
      *@param rhs Right Hand Side alfabeto a copiar
      *@return Devuelve el alfabeto asignado
  */
  alfabeto_t& operator=(const alfabeto_t& rhs);

  /**
      *@brief Pide el inicio del set del alfabeto
      *@return Devuelve un iterador al inicio del alfabeto
  */
  std::set<caracter_t>::iterator begin() { return alfa_.begin(); }

  /**
      *@brief Pide el final del set del alfabeto
      *@return Devuelve un iterador al final del alfabeto
  */
  std::set<caracter_t>::iterator end() { return alfa_.end(); }


};
