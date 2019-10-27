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
  unsigned estArranque_;
  char buff;
  estado_t const* estActual;

 public:
  dfa_t() {}
  ~dfa_t() {}
  void insert_estado( estado_t estado);
  void analiza( char caracter);

  unsigned find_estado( std::string name );

};
