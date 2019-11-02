/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 7: Construcción de Subconjuntos                                   *
 * ***************************************************************************/
//                              dfa_t.cpp

#include "dfa_t.hpp"


void dfa_t::insert_estado( estado_t estado) {
  estados_.insert(estado);
}



void dfa_t::analiza(char caracter) {
}


//Busca entre los estados el que tiene mismo nombre y devuelve el iterador
std::set<estado_t>::iterator dfa_t::find_estado(std::string& name){
  std::set<estado_t>::iterator it;
  for(it = estados_.begin(); it != estados_.end(); ++it)
  {
     if(it->get_name() == name ) return it;
  }
  return it;
}

void dfa_t::update_estado( std::set<estado_t>::iterator& it,const estado_t& nuevo) {
  std::cout << it->get_name() << '\n';
  if (it != estados_.end()){
    estados_.erase(it);
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


std::vector<std::string> dfa_t::get_est_acept() {
  std::vector<std::string> aux;
  for(auto it=estados_.begin() ; it != estados_.end(); ++it) {
    if(it->get_acept())
      aux.push_back("\""+it->get_name()+"\"");
  }
  return aux;
}

std::string dfa_t::get_est_arranque() {
  for(auto it=estados_.begin() ; it != estados_.end(); ++it) {
    if(it->is_arranque())
      return ("\""+it->get_name()+"\"");
  }
  return "calla";
}














