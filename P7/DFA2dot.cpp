/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                           *
 * Asignatura: Computabilidad y Algoritmia                                     *
 * Curso: 2º Ingeniería Informática                                            *
 * Editor: VIM                                                                 *
 * Estilo Google C++ Style Guide                                               *
 * Práctica 6: Automatas Finitos Deterministas                                 *
 * ****************************************************************************/
//                                DFA2dot.cpp


#include "DFA2dot.hpp"


DFA2dot_t::DFA2dot_t(std::string filein, std::string fileout) {
  filein_ = std::ifstream(filein);
  fileout_ = std::ofstream(fileout);
  read_file();
  write2dot();
}

DFA2dot_t::DFA2dot_t(dfa_t temp) {
  std::cout << "llego a dfa2dot y voy a igualar dfa\n";
  dfa_ = temp;
  std::cout << "dfa igualado, voy a imprimir\n";
  //rint_dfa();
  //write2dot();i
}


void DFA2dot_t::read_file() {
/*  alfabeto_t alfa;
  std::string cor;
  std::string aux;
  std::string delimiter=" ";
  if(filein_.is_open()) {
    while(!filein_.eof()) {
      getline(filein_,cor);
        if(cor[0] != '/' && cor[1] != '/') {
        //////////Set Alfabeto//////////
        std::cout << "//////////Set Alfabeto//////////\n";
        std::cout << "numero de simbolos: " << cor << std::endl;
        int n_alfa = stoi(cor);
        for(int i=0; i < n_alfa; i++){
          getline(filein_, cor);
          alfa.insert_symbol(cor[0]);
          std::cout << cor << '\n';
        }
        cor.clear();
        //////////Set Estados//////////
        std::cout << "//////////Set Estados//////////\n";
        getline(filein_, cor);
        std::cout << "numero estados: " << cor<< std::endl;
        int n_estados = stoi(cor);
        for(int i=0; i < n_estados; i++) {
          getline(filein_,cor);
          estado_t aux(i, cor);
          dfa_.insert_estado(aux);
        }
        cor.clear();
        std::cout << "//////////Set Estado Arranque/////////\n";
        //////////Set Estado Arranque/////////
        getline(filein_, cor);
        estado_t nuevo(dfa_.get_size(), cor);  //creamos un estado temporal
        auto ite = dfa_.find_estado(cor);
        nuevo = *ite;
        nuevo.set_arranque(true);

        //Establecemos el estado de arranque
        dfa_.update_estado(ite,nuevo); //elimina el estado con el mismo nombre
                                       //que se encuentra en la lista y pone el
                                       //nuevo
        //////////Set Numero de estados Acept//////////
        cor.clear();
        getline(filein_,cor);
        estados_acept_ = stoi(cor);
        nuevo.clean();
        for(int i=0; i < estados_acept_; i++) {
          getline(filein_, cor);
          auto iterador = dfa_.find_estado(cor);
          nuevo = *iterador;
          nuevo.set_acept(true);
          dfa_.update_estado(iterador,nuevo);
          cor.clear();
          nuevo.clean();
        }
        //////////Set Numero de transiciones//////////
        getline(filein_, cor);
        n_trans_ = stoi(cor);
        std::cout << "Nº de transiciones" << n_trans_ << std::endl;
        int pos = 0;
        getline(filein_, cor);
        print_dfa();
        for(int i=0; i < n_trans_; i++) {
          //Leo la linea con su formato
          pos = cor.find(delimiter);
          std::string desde = cor.substr(0,pos);
          cor.erase(0, pos + 1);
          pos = cor.find(delimiter);
          std::string con = cor.substr(0,pos);
          pos = cor.find(delimiter);
          cor.erase(0, pos + 1);
          std::string a = cor.substr(0, cor.size());
          pos = cor.find(delimiter);
          cor.erase(0, cor.size() -1);
          getline(filein_, cor);
          //creo estado
          auto it1 = dfa_.find_estado(desde);
          nuevo = *it1;
          nuevo.insert_tr(std::pair<char,std::string>(con[0],a));
          dfa_.update_estado(it1,nuevo);
          it1 = dfa_.find_estado(desde);
          it1->print_trans();
          nuevo.clean();
        }
      }
    }
  }*/
}

//std::string get_line( std::string aux) {
//  if(aux[0] != '/' && aux[1] != '/') {


void DFA2dot_t::print_dfa() {
  std::set<estado_t>::iterator it;
  std::cout << "estoy en print_dfa\n";
  for(it=dfa_.begin(); it != dfa_.end(); it++) {
    std::cout << "Estado en DFA: " << it->get_name();
    std::cout << " Arranque: " << it->is_arranque();
    std::cout << " Aceptacion : "<< it->get_acept();
    std::cout << " Id stado en DFA: " << it->get_id() << std::endl;
  }
  for(auto it = dfa_.begin(); it != dfa_.end(); it++) {
    for(auto jt = it->get_tran().begin(); jt != it->get_tran().end(); ++jt) {
      std::cout << "  \""+it->get_name()+"\"" << " -> ";
      std::cout << "  \""+jt->second.begin()->get_name()+"\""<<" [ label=\"" << jt->first << "\" ];\n";
    }
  }
}


void DFA2dot_t::write2dot() {
  fileout_ << "digraph DFA {\n";
  fileout_ << "  rankdir=LR;\n";
  fileout_ << "  size = \"10, 04\";\n";
  fileout_ << "  d2tstyleonly = true;\n";
  fileout_ << "  node [shape = none]; \" \";\n";
  fileout_ << "  node [shape = circle];\n";
  fileout_ << "  node [shape = doublecircle];";
  for(int i=0; i < estados_acept_; i++){
    fileout_ << dfa_.get_est_acept()[i] << " ";
  }
  fileout_ << ";\n";
  fileout_ << "  \" \"" << "->" << dfa_.get_est_arranque() << "\n";

  for(auto it = dfa_.begin(); it != dfa_.end(); it++) {
    for(auto jt = it->get_tran().begin(); jt != it->get_tran().end(); ++jt) {
      fileout_ << "  \""+it->get_name()+"\"" << " -> ";
      fileout_ << "  \""+jt->second.begin()->get_name()+"\""<<" [ label=\"" << jt->first << "\" ];\n";
    }
  }
  fileout_ << "}";

}


