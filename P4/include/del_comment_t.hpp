/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 4: Eliminador de comentarios                                      *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
//                         del_coment_t.hpp

//La clase del_comment_t es la encargada de realizar la eliminación de los com-
//entarios del fichero *.cpp, por ello sera quien DEFINA el AUTÓMATA que va a 
//moverse por el mapa para devoler o no si se debe imprimir en fichero


#pragma once
#include<iostream>
#include "dfa_t.hpp"
#include "alfabeto_t.hpp"
#include "estado_t.hpp"
#include <fstream>
#include <map>

class del_comment_t {
 private:
  dfa_t automata_;
  std::map<char, unsigned> transiciones_;
  alfabeto_t alfa_;
  std::ifstream fileIN_;
  std::ofstream fileOUT_;

 public:
  del_comment_t() {}
  ~del_comment_t() {}
  del_comment_t(std::iostream fileIN, std::ofstream fileOut);

 private:
  void definir_automata();

};
