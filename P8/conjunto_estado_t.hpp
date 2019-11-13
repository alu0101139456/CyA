/**
    *@file conjunto_estado_t.hpp
    *@version 1.0
    *@date 10/11/2019
    *@author Angel Julián Bolaño Campos
    *@title Gramáticas Regulares y Autómatas Finitos
*/

#pragma once

#include<set>
#include "estado_t.hpp"
#include<iostream>

class con_est_t {
 private:
  std::set<estado_t> conjuntos_;
  std::string name_;
  long long int id_;

 public:

  /**
      *@brief Constructor por defecto de conjuntos
  */
  con_est_t() {}

  /**
      *@brief Constructor de Conjuntos de estados
      *@param name Nombre del conjunto
      *@param aux Conjunto de estados agrupados
  */
  con_est_t(std::string name, std::set<estado_t> aux);

  /**
      *@brief Destructor de conjunto_estados
  */
  ~con_est_t() {}

  /**
      *@brief Constructor de copia de conjuntos
      *@param rhs Right Hand Side conjunto a copiar
  */
  con_est_t( const con_est_t& rhs);

  /**
      *@brief Realiza la transición de un conjunto a otro
      *@param aux caracter con el que se realiza a transición
  */
  std::set<estado_t> move( const char aux) const;

  /**
      *@brief Obtención del nombre que identifica al conjunto
      *@return String con el nombre del conjunto
  */
  std::string get_name() const{return name_;}

  /**
      *@brief Sobrecarga del operador de comparación <
      *@param rhs Right Hand Side conjunto con el que comparar
      *@return true si *this < rhs
  */
  int operator<(const con_est_t& rhs) const {
    return( this->id_ < rhs.id_);}

  /**
      *@brief Sobrecarga del operador de asignación
      *@param rhs Right Hand Side conjunto que vamos a asignar
      *@return Devuelve el conjunto copiado
  */
  con_est_t& operator=( const con_est_t& rhs);

  /**
      *@brief Sobrecarga del operador de comparación ==
      *@param rhs Right Hand Side conjunto con el que comparar
      *@return true si *this == rhs
  */
  bool operator==(const con_est_t& rhs) const {
    return (this->conjuntos_ == rhs.conjuntos_);}

};
