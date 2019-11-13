/**
    *@file dfa_t.hpp
    *@version 1.0
    *@date 10/11/2019
    *@author Angel Julián Bolaño Campos
    *@title Gramáticas Regulares y Autómatas Finitos
*/


#pragma once

#include<set>
#include<iostream>
#include<fstream>
#include<vector>

#include "estado_t.hpp"

class dfa_t {
 private:
  std::set<estado_t> estados_;

 public:

  /**
      *@brief Constructor por defecto de dfa
  */
  dfa_t() {}

  /**
      *@brief Destructor de dfa
  */
  ~dfa_t() {}

  /**
      *@brief Constructor de copia de dfa
      *@param rhs Right Hand Side dfa que copiar
  */
  dfa_t( const dfa_t& rhs) { this-> estados_ = rhs.estados_; }

  /**
      *@brief Inserción de estado en el dfa_t
      *@param estado Estado a insertar
  */
  void insert_estado( estado_t estado);

  /**
      *@brief Obtención del principio del set de estados
      *@return Devuelve un iterador al inicio del set de estados
  */
  std::set<estado_t>::iterator begin();

  /**
      *@brief Obtención del final del set de estados
      *@return Devuelve un iterador al final del set de estados
  */
  std::set<estado_t>::iterator end();

  /**
      *@brief Obtención de los estados del dfa
      *@return Devuelve el set de estados del DFA
  */
  std::set<estado_t> get_estados();

  /**
      *@brief Búsqueda de estados a través de su nombre
      *@param name Nombre del estado que se desea buscar
      *@return Devuelve un iterador al estado deseado o a end si no lo encuentra
  */
  std::set<estado_t>::iterator find_estado(std::string& name);

  /**
      *@brief Actualización de estado en el set
      *@param it Iterador que apunta a la posición del estado que se va a actualizar
      *@param nuevo Estado modifcado
  */
  void update_estado(std::set<estado_t>::iterator& it,const estado_t& nuevo);

  /**
      *@brief Obtención del número de estados del dfa
      *@return Devuelve el número de estados del dfa
  */
  unsigned get_size() { return estados_.size(); }

  /**
      *@brief Obtención de los estados de aceptación del dfa
      *@return Devuelve un vector con los estados de aceptación del vector
  */
  std::vector<std::string> get_est_acept();

  /**
      *@brief Obtención del estado de arranque
      *@return Devuelve un strin con el nombre del estado de arranque
  */
  std::string get_est_arranque();

  /**
      *@brief Sobrecarga del operador de asignacion
      *@param rhs Right Hand Side dfa que copiar
      *@return Devuele el dfa copiado *this
  */
  dfa_t& operator=(const dfa_t& rhs) {
    this->estados_ = rhs.estados_;
    return *this;
  }

  /**
      *@brief Imprime el DFA
  */
  void print();

};
