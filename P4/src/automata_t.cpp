


#include "../include/automata_t.h"




automata_t::automata_t(std::string aux, alfabeto_t Al) {
  Al_ = Al;
  fileIn_ = std::ifstream(aux);
  read_file();
}


void automata_t::read_file() {
  //char aux;
  int aux;
  if(fileIn_.is_open()) {
    while (!fileIn_.eof()) {
      aux = fileIn_.get();
      if ( compara(aux) ) {
        char a = aux;
        if (aux == '\n')
          std::cout << "encontre salto de linea\n";
          else std::cout << "encontre " << a << " \n";
      }
    }
  }
}


bool automata_t::compara(int aux) {
  std::set<int>::iterator it = Al_.find_symbol(aux);
  if ( it != Al_.end() ) return true;
      else return false;

}
