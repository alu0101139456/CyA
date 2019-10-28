/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 6: Automatas Finitos Deterministas                                *
 * ***************************************************************************/
//                              dfa_t.cpp

#include "../include/dfa_t.hpp"


void dfa_t::insert_estado( estado_t estado) {
  estados_.insert(estado);
}



void dfa_t::analiza(char caracter) {
}


//Busca entre los estados el que tiene mismo nombre y devuelve el id
std::set<estado_t>::iterator dfa_t::find_estado(std::string name){
  estado_t aux(0, name);
  std::set<estado_t>::iterator it = estados_.find(aux);
  return it;
}

void dfa_t::update_estado(std::string name, estado_t& nuevo) {
  std::set<estado_t>::iterator it = find_estado(name);
  if ( estados_.erase(it) != estados_.end()){
    estados_.insert(nuevo);
  }
}

std::set<estado_t> dfa_t::get_estados() {
 return estados_;

}

std::set<estado_t>::iterator dfa_t::begin() {
  return estados_.begin();
}

std::set<estado_t>::iterator dfa_t::end() {
  return estados_.end();
}
