/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶¶
 * Autor: Ángel Julián Bolaño Campos                                          *¶
 * Asignatura: Computabilidad y Algoritmia                                    *¶
 * Curso: 2º Ingeniería Informática                                           *¶
 * Editor: VIM                                                                *¶
 * Estilo Google C++ Style Guide                                              *¶
 * Práctica 5: Expresiones regulares                                          *
 * ****************************************************************************/
//                              EXPREG_T.CPP
#include "../include/expreg_t.hpp"


expreg_t::expreg_t(std::string expresion, alfabeto_t alfa, unsigned formato):
expre_(expresion),
alfa_(alfa),
formato_(formato){
  if (alfa_.is_in_alphabet(expre_)) {  //Se comprueba que todos los caracteres
                                       //pertenecen al alfabeto
    //expreg_t posfija = convert_to_posfija(1);
    convert();
  }
  else
    std::cerr << "Hay caracteres que no pertenecen al alfabeto establecido\n";
}




expreg_t expreg_t::convert_to_posfija(unsigned formato) {
  std::stack<caracter_t> pila;
  for(size_t i=0; i < expre_.size() - 1; i++) {
    caracter_t aux = alfa_.find(expre_[i]);
    if(aux.is_ParAb() || aux.is_ParCe() ) {
      pila.push(aux);
    }
    else if(aux.is_operando()) {
      std::cout << aux.get_caracter();
    }
    else if ( pila.empty() || pila.top().is_ParAb() ) {
       
    }
  }
}
//Convierte el string leido y añade entre dos operandos el caracter &
void expreg_t::convert() {
  std::string string_final;
  caracter_t previo = alfa_.find(expre_[0]);
  string_final = string_final.append(1,expre_[0]);
  for(size_t i=1; i < expre_.size(); i++) {
    if( previo.is_operando() && alfa_.find(expre_[i]) != alfa_.end() ) {
      string_final = string_final.append(1, '&');
      string_final = string_final.append(1, expre_[i]);
      previo = alfa_.find(expre_[i]);
    }
    else
      string_final = string_final.append(1, expre_[i]);
      previo = alfa_.find(expre_[i]);
  }
  std::cout << "String de entrada: " << expre_ << "\nString de salida: " <<
    string_final << std::endl;
}












