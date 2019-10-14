
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶¶
 * Autor: Ángel Julián Bolaño Campos                                          *¶
 * Asignatura: Computabilidad y Algoritmia                                    *¶
 * Curso: 2º Ingeniería Informática                                           *¶
 * Editor: VIM                                                                *¶
 * Estilo Google C++ Style Guide                                              *¶
 * Práctica 4: Eliminador de comentarios                                      *¶
 * ***************************************************************************/

//Librerias de la carpeta INCLUDE
#include "../include/alfabeto_t.hpp"
#include "../include/automata_t.hpp"
#include "../include/del_comment_t.hpp"
#include <fstream>

#include<iostream>

int main ()
{
  alfabeto_t A;

  automata_t a("prueba.cpp", A);
}
