/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶¶
 * Autor: Ángel Julián Bolaño Campos                                          *¶
 * Asignatura: Computabilidad y Algoritmia                                    *¶
 * Curso: 2º Ingeniería Informática                                           *¶
 * Editor: VIM                                                                *¶
 * Estilo Google C++ Style Guide                                              *¶
 * Práctica 5: Expresiones regulares                                          *
 * ****************************************************************************/
//                                EXPREG_T.CPP
#include "../include/expreg_t.hpp"


expreg_t::expreg_t(std::string expresion, alfabeto_t alfa, unsigned formato):
expre_(expresion),
alfa_(alfa),
formato_(formato){
  if (alfa_.is_in_alphabet(expre_)) {
    std::cout << "UHH ESTA TODO EN EL ALFABETO ASI QUE CHACHI\n";
  }
  else
    std::cout << "Hay caracteres que no pertenecen al alfabeto establecido\n";
}

