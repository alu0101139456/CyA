/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                           *
 * Asignatura: Computabilidad y Algoritmia                                     *
 * Curso: 2º Ingeniería Informática                                            *
 * Editor: VIM                                                                 *
 * Estilo Google C++ Style Guide                                               *
 * Práctica 6: Automatas Finitos Deterministas                                 *
 * ****************************************************************************/
//                                DFA2dot.cpp


#include "../include/DFA2dot.hpp"


DFA2dot_t::DFA2dot_t(std::string filein, std::string fileout) {
  filein_ = std::ifstream(filein);
  fileout_ = std::ofstream(fileout);
  read_file();
}


void DFA2dot_t::read_file() {
  alfabeto_t alfa;
  std::string cor;
  std::string aux;
  std::string delimiter=" ";
  if(filein_.is_open()) {
    while(!filein_.eof()) {
      getline(filein_,cor);
      if(cor[0] != '/' && cor[1] != '/') {
        std::cout << "numero de simbolos: " << cor << std::endl;
        int n_alfa = stoi(cor);
        for(int i=0; i < n_alfa; i++){
          getline(filein_, cor);
          alfa.insert_symbol(cor[0]);
          std::cout << cor << '\n';
        }
        getline(filein_, cor);
        std::cout << "numero estados: " << cor<< std::endl;
        int n_estados = stoi(cor);
        for(int i=0; i < n_estados; i++) {
          getline(filein_,cor);
          dfa_.insert_estado(estado_t(i, cor));
          std::cout << "estados leidos: "  << cor << '\n';
        }
        getline(filein_, cor);
        dfa_.find_estado(cor).set_arranque(true);
        std::cout << "va?" << dfa_.find_estado(cor).get_id() << "flipalo";
      }
    }
  }
}

