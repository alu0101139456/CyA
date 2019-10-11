/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 2: Análisis de Texto                                              *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
//lenguaje_t.hpp

#include<iostream>
#include<set>
#include<fstream>



class lenguaje_t {
 private:
  std::set<std::string> leng_;

 public:
  lenguaje_t();
  ~lenguaje_t(){}

  void insert_cadena(std::string cadena);






};

