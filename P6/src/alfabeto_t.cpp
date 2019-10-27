/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 6: Automatas Finitos Deterministas                                *
 *****************************************************************************/
//

#include "../include/alfabeto_t.hpp"


alfabeto_t::alfabeto_t () {
  //insert_from_file();

}

void alfabeto_t::insert_symbol( char symbol) {
  alfa_.insert(caracter_t(symbol, 0, OPERANDO, 0));
}


void alfabeto_t::insert_from_file() {

  std::string aux;
  std::ifstream alfaFile("alfabeto.txt");
  getline(alfaFile, aux);
  //Metemos todos los caracteres leidos en objetos tipo Carater_t
  // ----> caracter_t(char car, unsigned pri, int tip, int ari)
  // Primero introducimos los OPERANDOS
  for(unsigned i=0; i<aux.length(); i++) {
    //Los objetos caracter los insertamos en el set
    alfa_.insert(caracter_t(aux[i], 0, OPERANDO, 0));
  }
  //Luego introducimos los OPERADORES con su prioridad y aridad
  for(int i=0; i<2; i++) {
    getline(alfaFile, aux);
    for( unsigned j=0; j<aux.size(); j+=2) {
       alfa_.insert(caracter_t(aux[j], aux[j+1], OPERADOR, i+1));
    }
  }
  alfaFile.close();
}

bool alfabeto_t::pertenece(caracter_t caracter) {
  std::set<caracter_t>::iterator it = alfa_.find(caracter);
  if (it != alfa_.end()) return true;
  else return false;
}


std::set<caracter_t>::iterator alfabeto_t::find_symbol(char sym) {
  caracter_t aux(sym, 0, 0, 0);
  //if(alfa_.find(aux) != alfa_.end()) {
  return alfa_.find(aux);
  //}
}

caracter_t alfabeto_t::find(char sym) {
  caracter_t aux(sym, 0, 0, 0);
  std::set<caracter_t>::iterator it = alfa_.find(aux);
  return *it;
}


std::set<caracter_t>::iterator alfabeto_t::end() {
  return alfa_.end();
}

bool alfabeto_t::is_in_alphabet(std::string expresion) {
  int count=0;
  for(unsigned i=0; i<expresion.size(); i++) {
    caracter_t aux(expresion[i],0,0,0);
    if( !pertenece(aux)) {
      count++;
    }
  }
  return count == 0? 1: 0;
}

alfabeto_t::alfabeto_t( const alfabeto_t& rhs){
  this->alfa_ = rhs.alfa_;
}

alfabeto_t& alfabeto_t::operator=(const alfabeto_t& rhs) {
  this->alfa_ = rhs.alfa_;
  return *this;
}






