/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 4: Eliminador de comentarios                                      *
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
  void set_arranque( unsigned estado) {
    estArranque_ = estado;
    estActual = &(*estados_.find(estArranque_));
  }
  bool analiza( char caracter);


};
