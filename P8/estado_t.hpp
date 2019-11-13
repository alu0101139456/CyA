/**
    *@file estado_t.hpp
    *@version 1.0
    *@date 10/11/2019
    *@author Angel Julián Bolaño Campos
    *@title Gramáticas Regulares y Autómatas Finitos
*/

#pragma once
#include<iostream>
#include <map>
#include<set>
class estado_t;
typedef std::map<char, std::set<estado_t>> trans_map;


class estado_t {
 private:
  long long int id_;
  std::string name_;
  bool acept_;
  trans_map transiciones_;
  std::set<estado_t> e_transiciones_;
  bool arranque=false;



 public:

  /**
      @brief Constructor por defecto de estado
  */
  estado_t() {}

  /**
      *@brief Destructor de estado
  */
  ~estado_t() {}

  /**
      *@brief Constructor de estado
      *@param name String que contiene el nombre del estado
  */
  estado_t(std::string name): name_(name) {
    id_ = 0;
    acept_ = false;
    for (int i = 0; i < name.size(); ++i)
      id_ += 131*id_ + name[i];

  }

  /**
      *@brief Constructor de estado
      *@param id Identificador del estado
      *@param name String que contiene el nombre del estado
  */
  estado_t(unsigned id, std::string name);

  /**
      *@brief Constructor de opia de estado
      *@param rhs Right Hand Side Estado que copiar
  */
  estado_t(const estado_t& rhs);

  /**
      *@brief Constructor de estado
      *@param id Identificador del estado
      *@param name String que contiene el nombre del estado
      *@param acpt Booleano que indica si el estado es de aceptación
      *@param tr Mapa de transiciones del estado
      *@param arr Booleano que indica si el estado es de arranque
  */
  estado_t(unsigned id, std::string name, bool acpt, trans_map tr, bool arr):
    id_(id),
    name_(name),
    acept_(acpt),
    transiciones_(tr),
    arranque(arr){}

  /**
      *@brief Añade una e_transición al estado
      *@param aux Estado al que llega con la e_transición
  */
  void insert_e_tr(estado_t aux);

  /**
      *@brief Limpia la información de estado
  */
  void clean();

  /**
      *@brief Añade una transición al estado
      *@param caracter Caracter con el que se realiza la transición
      *@param aux Estado al que llega con la transición
  */
  void insert_tr (char caracter, estado_t& aux);

  /**
      *@brief Obtención del identificador del estado
      *@return Devuelve el identificador del estado
  */
  long long int get_id() const { return id_; }

  /**
      *@brief Obtención del nombre del estado
      *@return Devuelve un strig con el nombre del estado
  */
  std::string get_name() const {return name_;}

  /**
      *@brief Comprueba si es un estado de aceptación
      *@return Devuelve true si es un estado de aceptación y false en otro caso
  */
  bool get_acept() const { return acept_; }

  /**
      *@brief Comprueba si es un estado de arranque
      *@return Devuelve true si es un estado de arranque y false en otro caso
  */
  int is_arranque() const { return arranque; }

  /**
      *@brief Obtención de las transiciones del estado
      *@return Devuelve las transiciones del estado
  */
  const trans_map& get_tran() const {return transiciones_;}

  /**
      *@brief Obtención del numero de transiciones del estado
      *@return Devuelve el número de transiciones del estado
  */
  int get_n_trans()const { return transiciones_.size(); }

  /**
      *@brief Obtención del numero de e_transiciones del estado
      *@return Devuelve el número de e_transiciones del estado
  */
  int get_n_e_trans() const {return e_transiciones_.size();}

  /**
      *@brief Obtención del principio del conjunto dee_transiciones
      *@return Devuelve un iterador al inicio del set de e_transiciones
  */
  std::set<estado_t>::iterator get_eps_begin() const {return e_transiciones_.begin();}

  /**
      *@brief Obtención del final del conjunto dee_transiciones
      *@return Devuelve un iterador al final del set de e_transiciones
  */
  std::set<estado_t>::iterator get_eps_end() const { return e_transiciones_.end(); }

  /**
      *@brief Obtención del estado al los que se llega con un símbolo
      *@param symbol Símbolo utilizado en la transición
      *@return Devuelve el set de estados al que llega con el símbolo indcado
  */
  std::set<estado_t> get_trans_with( char symbol) const;

  /**
      *@brief Modifica el tipo de estado de aceptación o no
      *@param aux Booleano que indica si será o no un estado de aceptación
  */
  void set_acept(bool aux) { acept_ = aux; }

  /**
      *@brief Modifica el mapa de transiciones
      *@param map Nuevo mapa de transiciones
  */
  void set_trans(trans_map map) { transiciones_ = map; }

  /**
      *@brief Modifica si el estado es de arranque
      *@param aux Booleano que indica si será o no un estado de arranque
  */
  void set_arranque(bool aux) { arranque = aux; }

  /**
      *@brief Sobrecarga del operador de comparación <
      *@param rhs Right Hand Side estado con el que vamos a comparar
      *@return Devuelve true si this < rhs
  */
  bool operator<(const estado_t& rhs) const {
    return (this->get_id() < rhs.get_id());}

  /**
      *@brief Sobrecarga del operador de comparación ==
      *@param rhs Right Hand Side estado con el que vamos a comparar
      *@return Devuelve true si this == rhs
  */
  bool operator==(const estado_t& rhs) const {
    return (this->get_name() == rhs.get_name()); }

  /**
      *@brief Sobrecarga del operador de asignación
      *@param rhs Right Hand Side estado que vamos a copiar
      *@return Devuelve *this
  */
  estado_t& operator=(const estado_t& rhs);
};
