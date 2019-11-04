/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 7: Construcción de Subconjuntos                                   *
 ****************************************************************************/ 
//                                nfa_t.hpp
#include "nfa_t.hpp"


void nfa_t::insert_estado(estado_t estado) {
  estados_.insert(estado);
}

std::set<estado_t> nfa_t::e_clausura(std::set<estado_t> T) {
  std::stack<estado_t> pila_estados;
  for(auto it=T.begin(); it != T.end(); ++it) {
    pila_estados.push(*it);
  }
  std::set<estado_t> e_clausura = T;
  while (!pila_estados.empty()) {
    estado_t temp = pila_estados.top();
    pila_estados.pop();
    for( auto it=temp.get_eps_begin(); it != temp.get_eps_end(); ++it) {
      if(e_clausura.insert(*it).second) //Insert devuelve true o false si el
                                        //elemento ya estaba en el set
        pila_estados.push(*it);
    }
  }
  return e_clausura;
}

std::set<estado_t> nfa_t::e_clausura(estado_t T) {
  std::stack<estado_t> pila_estados;
  pila_estados.push(T);
  std::set<estado_t> e_clausura;
  e_clausura.insert(T);
  while (!pila_estados.empty()) {
    estado_t temp = pila_estados.top();
    pila_estados.pop();
    for( auto it=temp.get_eps_begin(); it != temp.get_eps_end(); ++it) {
      if(e_clausura.insert(*it).second) //Insert devuelve true o false si el
                                        //elemento ya estaba en el set
        pila_estados.push(*it);
    }
  }
  return e_clausura;
}

std::set<estado_t>::iterator nfa_t::find_estado(std::string& name){
  std::set<estado_t>::iterator it;
  for(it = estados_.begin(); it != estados_.end(); ++it) {
     if(it->get_name() == name ) return it;
  }
  return it;
}

void nfa_t::update_estado(std::set<estado_t>::iterator& it,const estado_t& nuevo) {
  if (it != estados_.end()) {
    estados_.erase(it);
    estados_.insert(nuevo);
  }
}

std::set<estado_t>::iterator nfa_t::begin() {
  return estados_.begin();
}

std::set<estado_t>::iterator nfa_t::end() {
  return estados_.end();
}

std::vector<std::string> nfa_t::get_est_acept() {
  std::vector<std::string> aux;
  for(auto it=estados_.begin() ; it != estados_.end(); ++it) {
    if(it->get_acept())
      aux.push_back("\""+it->get_name()+"\"");
  }
  return aux;
}

std::string nfa_t::get_est_arranque_p() {
  auto it = estados_.end();
  for(it=estados_.begin() ; it != estados_.end(); ++it) {
    if(it->is_arranque())
      return ("\""+it->get_name()+"\"");
  }
  return it->get_name();
}

estado_t nfa_t::get_est_arranque() {
auto it = estados_.end();
  for(it=estados_.begin() ; it != estados_.end(); ++it) {
    if(it->is_arranque())
      return (*it);
  }
  return *it;
}




