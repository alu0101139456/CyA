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
        //////////Set Alfabeto//////////
        std::cout << "numero de simbolos: " << cor << std::endl;
        int n_alfa = stoi(cor);
        for(int i=0; i < n_alfa; i++){
          getline(filein_, cor);
          alfa.insert_symbol(cor[0]);
          std::cout << cor << '\n';
        }
        cor.clear();
        //////////Set Estados//////////
        getline(filein_, cor);
        std::cout << "numero estados: " << cor<< std::endl;
        int n_estados = stoi(cor);
        for(int i=0; i < n_estados; i++) {
          getline(filein_,cor);
          estado_t aux(i, cor);
          dfa_.insert_estado(aux);
        }
        print_dfa();
        
        cor.clear();
        //////////Set Estado Arranque/////////
        getline(filein_, cor);
        estado_t nuevo(dfa_.get_size(), cor);  //creamos un estado temporal
        nuevo.set_arranque(true); //Establecemos el estado de arranque
        dfa_.update_estado(cor,nuevo); //elimina el estado con el mismo nombre
                                       //que se encuentra en la lista y pone el
                                       //nuevo
        print_dfa();
        //////////Set Numero de estados Acept//////////
        
        cor.clear();
        getline(filein_,cor);
        int est_acept = stoi(cor);
        std::cout << "Nº estados Aceptacion: "<< est_acept << std::endl;
        nuevo.clean();
        for(int i=0; i < est_acept; i++) {
          getline(filein_, cor);
          nuevo.set_acept(true);
          nuevo.set_name(cor);
          dfa_.update_estado(cor,nuevo);
          cor.clear();
          nuevo.clean();
        }


        print_dfa();
        std::set<estado_t>::iterator it;
        getline(filein_, cor);
        int n_trans = stoi(cor);
        std::cout << "Nº de transiciones" << n_trans << std::endl;
      }
    }
  }
}

void DFA2dot_t::print_dfa() {
  std::set<estado_t>::iterator it;
  for(it=dfa_.begin(); it != dfa_.end(); it++) {
    std::cout << "Estado en DFA: " << it->get_name();
    std::cout << " Arranque: " << it->is_arranque();
    std::cout << " Aceptacion : "<< it->get_acept();
    std::cout << " Id stado en DFA: " << it->get_id() << std::endl;
  }
}



