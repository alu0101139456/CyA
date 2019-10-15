/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 4: Eliminador de comentarios                                      *
 * ***************************************************************************/
//                              dfa_t.cpp

#include "../include/dfa_t.hpp"


void dfa_t::insert_estado( estado_t estado) {
  estados_.insert(estado);
}


bool dfa_t::analiza(char caracter) {
  auto siguiente = estActual.get_tran().find(caracter);

  if(siguiente == estActual.get_tran().end())
    return false;

  unsigned estado_sig = siguiente->second;

}


