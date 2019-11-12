/**
    *@file cadena_t.hpp
    *@version 1.0
    *@date 10/11/2019
    *@author Angel Julián Bolaño Campos
    *@title Gramáticas Regulares y Autómatas Finitos
*/


#pragma once
#include<iostream>
#include "symbol_t.hpp"
#include<vector>


class cadena_t{
 private:
  std::string name_;
  std::vector<symbol_t> cadena_;
  long int id_;
  bool is_terminal_;

 public:

  /**
      *@brief Constructor por defecto de cadena_t.
  */
  cadena_t():id_(0), is_terminal_(true) {}

  /**
      *@brief Destructor de cadena_t.
  */
  ~cadena_t() {}

  /**
      *@brief Constructor de copia de cadena_t
      *@param rhs Right Hand Side cadena_t a copiar
  */
  cadena_t(const cadena_t& rhs);

  /**
      *@brief Concatena un símbolo a la cadena
      *@param aux Símbolo a concatenar a la cadena
  */
  void append( symbol_t aux);

  /**
      *@brief Obtener la cadena en forma de vector
      *@return Vector contenedor de los símbolos dela cadena
  */
  const std::vector<symbol_t>& get_cadena() const;

  /**
      *@brief Obtener identificador de la cadena
      *@return Devuelve el identificador único de nuestra cadena
  */
  long int get_id() const;

  /**
      *@brief Comprueba si la cadena es terminal.
      *@return Devuelve true en caso de que sea una cadena terminal y false en otro caso
  */
  bool is_terminal() const;

  /**
      *@brief Obtener el string de la cadena
      *@return Devuelve la cadena en forma de string
  */
  std::string get_name() const;

  /**
      *@brief Sobrecarga del operador de asignación
      *@param rhs Right Hand Side cadena a copiar
      *@return Devuelve la cadena copiada
  */
  cadena_t& operator=(const cadena_t& rhs);

  /**
      *@brief Sobrecarga del operador de comparación <
      *@param rhs Right Hand Side alfabeto con el ue comparar
      *@return Devuelve true si el alfabeto a la izquierda es menor al de la derecha
  */
  bool operator<(const cadena_t& rhs) const;
};
