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
  }
  else
    std::cerr << "Hay caracteres que no pertenecen al alfabeto establecido\n";
}

expreg_t expreg_t::convert_to_posfija(unsigned formato) {
  std::stack<caracter_t> pila;
  for(size_t i=0; i < expre_.size() - 1; i++) {
    caracter_t aux = alfa_.find(expre_[i]);
    if(aux.is_ParAb() || !aux.is_ParAb() ) {
      pila.push(aux);
    }
    else if(aux.is_operando()) {
      std::cout << aux.get_caracter();
    }
    else if ( pila.empty() || pila.top().is_ParAb() ) {
       
    }
  }
}

}
