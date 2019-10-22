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
    expreg_t posfija = convert_to_posfija(1);
    //convert();
    std::cout << ex_pf_ << " salio....\n";
  }
  else
    std::cerr << "Hay caracteres que no pertenecen al alfabeto establecido\n";
}




expreg_t expreg_t::convert_to_posfija(unsigned formato) {
  for(size_t i=0; i < expre_.size() - 1; i++) {
    caracter_t aux = alfa_.find(expre_[i]);
    if(aux.is_ParAb()) {
      pila_.push(aux);
    }
    if(aux.is_operando) {
      ex_pf_.push_back(aux.get_caracter());
    }
    else if(pila_.empty() || pila_.top().is_ParAb()) {
      pila_.push(aux.get_caracter());
    }
    else if(aux.is_ParCe()) {
      while (!pila_.top().is_ParAb()) {
        
      }
    }
  }
}




//Convierte el string leido y añade entre dos operandos el caracter &
void expreg_t::convert() {
  std::string string_final;
  caracter_t previo = alfa_.find(expre_[0]);
  string_final = string_final.append(1,expre_[0]);
  for(size_t i=1; i < expre_.size(); i++) {
    caracter_t aux = alfa_.find(expre_[i]);
    if( previo.is_operando() && aux.is_operando() ){
      string_final = string_final.append(1, '&');
      string_final = string_final.append(1, aux.get_caracter());
      previo = aux;
    }
    else
      string_final = string_final.append(1, expre_[i]);
      previo = aux;
  }
  if ( string_final[string_final.size()-1] == '*' )
    string_final = string_final.append(1, '&');

  //std::cout << "String de entrada: " << expre_ << "\nString de salida: " <<
  //  string_final << std::endl;
}












