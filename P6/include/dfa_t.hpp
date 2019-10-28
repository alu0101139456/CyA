/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 6: Automatas Finitos Deterministas                                *
 * ***************************************************************************/
//                              dfa_t.hpp


#include<set>
#include<iostream>
#include<fstream>

#include "alfabeto_t.hpp"

#include "estado_t.hpp"

class dfa_t {
 private:
  alfabeto_t Al_;
  std::set<estado_t> estados_;

 public:
  dfa_t() {}
  ~dfa_t() {}
  void insert_estado( estado_t estado);
  void analiza( char caracter);
  std::set<estado_t>::iterator begin();
  std::set<estado_t>::iterator end();
  std::set<estado_t> get_estados();
  std::set<estado_t>::iterator find_estado(std::string name);
  void update_estado(std::string name, estado_t& nuevo);
  
  unsigned get_size() { return estados_.size(); }

};
