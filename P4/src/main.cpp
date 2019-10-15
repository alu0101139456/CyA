
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶¶
 * Autor: Ángel Julián Bolaño Campos                                          *¶
 * Asignatura: Computabilidad y Algoritmia                                    *¶
 * Curso: 2º Ingeniería Informática                                           *¶
 * Editor: VIM                                                                *¶
 * Estilo Google C++ Style Guide                                              *¶
 * Práctica 4: Eliminador de comentarios                                      *¶
 * ***************************************************************************/

//Librerias de la carpeta INCLUDE

#include "../include/del_comment_t.hpp"
#include "../include/alfabeto_t.hpp"

#include <fstream>
#include<iostream>

int main (int argc, char* argv[])
{
  alfabeto_t A;
  std::ifstream in (argv[1]);
  std::ofstream out(argv[2]);
  del_comment_t a(in, out);
}
