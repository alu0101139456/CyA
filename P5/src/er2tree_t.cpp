/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 5: Expresiones regulares                                          *
 * **************************************************************************/
//                                er2tree.cpp


#include "../include/er2tree_t.hpp"


er2tree_t::er2tree_t(std::string filein, std::string fileout) {
  fileIn_ = std::ifstream(filein);
  fileOut_ = std::ofstream(fileout);

  read_from_file();

}

void er2tree_t::read_from_file() {
  std::string ch;

  if(fileIn_.is_open()) {
    int i = 0;
    while (getline(fileIn_, ch)) {
      arboles_.push_back(tree_t(expreg_t(ch, alfa_, INFIJA)));
      arboles_[i].print_in_file(fileOut_);
      i++;
    }
    fileIn_.close();
  }
  else std::cerr << "Error al abrir el fichero" << std::endl;

}


