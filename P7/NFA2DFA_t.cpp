/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 7: Construcción de Subconjuntos                                   *
 ****************************************************************************/ 
//                                NFA2DFA_T.cpp

#include "NFA2DFA_t.hpp"


nfa2dfa_t::nfa2dfa_t(std::string filein, std::string fileout) {
  FileIn_ = std::ifstream(filein);
  FileOut_ = std::ofstream(fileout);

  read_file();

}

void nfa2dfa_t::read_file() {
  std::string aux;
  if(FileIn_.is_open()) {
    while(!FileIn_.eof()) {
      getline(FileIn_, aux);
      if( aux[0] == '/' && aux[1] == '/') {
        FileOut_ << aux;
      }
      else {
        read_alpha_from_file();
      }
    }
  }
  else { std::cerr << "ATENCIÓN: Error en lectura de fichero de entrada\n";}

}


void nfa2dfa_t::read_alpha_from_file() {
  if(reader.alpha == false) {

    reader.alpha = true;
  }
  else {
    read_states_from_file();
  }

}

void nfa2dfa_t::read_states_from_file() {
  if(reader.states == false) {

    reader.states = true;
  }
  else {
    read_start_state_from_file();
  }
}
