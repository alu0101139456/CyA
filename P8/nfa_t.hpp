/**
    *@file nfa_t.hpp
    *@version 1.0
    *@date 10/11/2019
    *@author Angel Julián Bolaño Campos
    *@title Gramáticas Regulares y Autómatas Finitos
*/


#pragma once
#include<iostream>
#include<fstream>
#include<set>
#include<vector>
#include<stack>
#include<queue>

#include "estado_t.hpp"
#include "conjunto_estado_t.hpp"
#include "dfa_t.hpp"
#include "alfabeto_t.hpp"

const char EPS = '~';

class nfa_t {
 private:
  std::set<estado_t> estados_;
  estado_t arranque_;
  alfabeto_t alpha;

 public:

  /**
      *@brief Constructor por defecto del nfa
  */
  nfa_t() {}

  /**
      *@brief Contructor de copia del nfa
      *@param rhs Right Hand Side nfa que copiar
  */
  nfa_t(const nfa_t& rhs);

  /**
      *@brief Destructor de la clase nfa
  */
  ~nfa_t() {}


  /**
      *@brief Inserta un estado en el nfa
      *@param estado Estado a insertar
  */
  void insert_estado(estado_t estado);

  /**
      *@brief Realiza la e_clausura sobre un conjunto de estados
      *@param T Conjunto de estados sobre el que se realiza la e_clausura
      *@return Devuelve el conjunto de estados que se alcanza usando e_transiciones
  */
  std::set<estado_t> e_clausura(const std::set<estado_t>& T);

  /**
      *@brief Convierte el nfa en un DFA
      *@return Devuelve una copia del DFA resultante
  */
  dfa_t convert_to_dfa();

  /**
      *@brief Imprime el Nfa
  */
  void print();

  /**
      *@brief Comprueba la pertenencia de un conjunto de estados a un conjunto de conjuntos
      *@param a Conjunto a comprobar
      *@param b Conjunto en el que buscaremos
      *@return Devuelve un iterador a la posición donde se encontró el conjunto o a end
  */
  std::set<con_est_t>::iterator pertenece(const con_est_t& a,\
                                          const std::set<con_est_t>&b);

  /**
      *@brief Vuelca el nfa en un fichro
  */
  void print_file_out(std::string namefile);


  /**
      *@brief Obtención del principio del set de estados
      *@return Devuelve un iterador apuntando al inicio del set de estados
  */
  std::set<estado_t>::iterator begin();

  /**
      *@brief Obtención del final del set de estados
      *@return Devuelve un iterador apuntando al final del set de estados
  */
  std::set<estado_t>::iterator end();

  /**
      *@brief Busca un estado en el set a través de su nombre
      *@param name Nombre a buscar
      *@return Devuelve un iterador apuntando al elemento buscado. Si no se encontró apunta a end
  */
  std::set<estado_t>::iterator find_estado(std::string& name);

  /**
      *@brief Actualiza el estado en el nfa
      *@param it Iterador apuntando a la posición actual del elemento
      *@param nuevo Estado a modificar en el nfa
  */
  void update_estado(std::set<estado_t>::iterator& it,const estado_t& nuevo);

  /**
      *@brief Configuración del alfabeto del nfa
      *@param alfabeto Alfabeto que vamos a utilizar
  */
  void set_alpha(const alfabeto_t& alfabeto){ alpha = alfabeto;}

  /**
      *@brief Obtención del numero total de estados del nfa
      *@return Devuelve el tamaño del set de estados del nfa
  */
  unsigned get_n_estados() { return estados_.size(); }

  /**
      *@brief Obtención de los estados de aceptación
      *@return Devuelve un vector con los diferentes estados de aceptación
  */
  std::vector<std::string> get_est_acept();

  /**
      *@brief Obtención del estado de arranque del nfa
      *@return Devuelve una copia del estado de arranque del nfa
  */
  estado_t get_est_arranque();

  /**
      *@brief Obtención del nombre del estado de arranque
      *@return Devuelve un string con el nombre del estado de arranque
  */
  std::string get_est_arranque_p();

  /**
      *@brief Sobrecarga del operador de asignación
      *@param rhs Right Hand Side nfa que copiar
      *@return Devuelve el nfa copiado
  */
  nfa_t& operator=(const nfa_t& rhs);



};
