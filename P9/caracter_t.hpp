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
      *@param rhs Right Hand Side caracter a copiar
  */
  caracter_t( const caracter_t& rhs);

  /**
      *@brief Modifica el valor de caracter
      *@param car Valor por el que sustituir el caracter
  */
  void set_caracter( char car);

  /**
      *@brief Modifica el prioridad del caracter
      *@param pri Valor de prioridad a asignar al caracter
  */
  void set_prioridad(unsigned pri);

  /**
      *@brief Modifica el tipo de caracter
      *@param tipo Especifica si el caracter es un operando u operador
  */
  void set_tipo(int tipo);

  /**
      *@brief Obtención de la aridad del operador
      *@return Devuelve un entero con la aridad del operador
  */
  int get_ari() { return aridad_; }

  /**
      *@brief Obtención del caracter
      *@return Devuelve el caracter que representa al objeto
  */
  char get_caracter() const;

  /**
      *@brief Obtención de la prioridad
      *@return Devuelve la prioridad del operador
  */
  unsigned get_prioridad();

  /**
      *@brief Obtención del tipo de caracter
      *@return devuelve el tipo de caracter
  */
  int get_tipo();

  /**
      *@brief Comprobación del tipo de caracter operando
      *@return Devuelve true si el caracter es un operando y false en otro caso
  */
  bool is_operando();

  /**
      *@brief Comprobación del tipo de caracter operando
      *@return Devuelve true si el caracter es un operando y false en otro caso
  */
  bool is_a_operando();


  /**
      *@brief Comprobación del tipo de caracter operando
      *@return Devuelve true si el caracter es un operando y false en otro caso
  */
  bool is_operador();


  /**
      *@brief Comprobación de que el caracter es un paréntesis abierto
      *@return Devuelve true si el caracter es un paréntesis abierto y false en otro caso
  */
  bool is_ParAb();

  /**
      *@brief Comprobación de que el caracter es un paréntesis cerrado
      *@return Devuelve true si el caracter es un paréntesis cerrado y false en otro caso
  */
  bool is_ParCe();

  /**
      *@brief Sobrecarga del operador de comparación ==
      *@param rhs Right Hand Side caracter con el que comparamos
      *@return Devuelve true si ambos caracteres son iguales
  */
  bool operator==(const caracter_t& rhs) const;

  /**
      *@brief Sobrecarga del operador de comparación <
      *@param rhs Right Hand Side caracter con el que comparamos
      *@return Devuelve true si *this < rhs
  */
  bool operator<(const caracter_t& rhs) const;

  /**
      *@brief Sobrecarga del operador de asignación
      *@param rhs Right Hand Side caracter con el que asignamos
      *@return Devuelve caracter copiado *this
  */
  caracter_t& operator=(const caracter_t& rhs);

};
