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
      if( (aux[0] == '/') && (aux[1] == '/')) {
        FileOut_ << aux << '\n';
      }
      else {
        read_alpha_from_file(aux);
      }
    }
  }
  else { std::cerr << "ATENCIÓN: Error en lectura de fichero de entrada\n";}

}


void nfa2dfa_t::read_alpha_from_file(std::string& word) {
  if(reader.alpha == false) {
    alfabeto_t alpha;
    int n_alpha = stoi(word);
    for(int i = 0; i < n_alpha; i++) {
      getline(FileIn_, word);
      alpha.insert_symbol(word[0]);
    }
    reader.alpha = true;
  }
  else {
    read_states_from_file(word);
  }

}

void nfa2dfa_t::read_states_from_file(std::string& word) {
  if(reader.states == false) {
    int n_states = stoi(word);
    for(int i=0; i < n_states; i++) {
      getline(FileIn_, word);
      estado_t aux(i, word);
      Nfa_.insert_estado(aux);
    }
    reader.states = true;
  }
  else {
    read_start_state_from_file(word);
  }
}

void nfa2dfa_t::read_start_state_from_file(std::string& word) {
  if(reader.start == false) {
    estado_t start_state(Nfa_.get_n_estados(), word);
    auto it = Nfa_.find_estado(word);
    start_state = *it;
    start_state.set_arranque(true);
    Nfa_.update_estado(it, start_state);
    reader.start = true;
  }
  else {
    read_acept_states_from_file(word);
  }
}

void nfa2dfa_t::read_acept_states_from_file(std::string& word) {
  estado_t temp;
  if(reader.a_state == false) {
    int acept_states = stoi(word);
    for(int i=0; i < acept_states; i++) {
      getline(FileIn_, word);
      auto it = Nfa_.find_estado(word);
      temp = *it;
      temp.set_acept(true);
      Nfa_.update_estado(it, temp);
    }
    reader.a_state = true;
  }
  else {
    read_transitions_from_file(word);
  }
}

void nfa2dfa_t::read_transitions_from_file(std::string& word) {
  if(reader.a_state == false) {
    estado_t e_trans;
    int pos=0;
    std::string delimiter = " ";
    int n_trans = stoi(word);
    getline(FileIn_, word);
    for(int i=0; i < n_trans ; i++) {
      pos = word.find(delimiter);
      std::string desde = word.substr(0,pos);
      word.erase(0, pos + 1);
      pos = word.find(delimiter);
      std::string con = word.substr(0,pos);
      pos = word.find(delimiter);
      word.erase(0, pos + 1);
      std::string a = word.substr(0, word.size());
      pos = word.find(delimiter);
      word.erase(0, word.size() -1);
      //creo estado
      auto it = Nfa_.find_estado(desde);
      e_trans = *it;
      if( con == "~") e_trans.insert_e_tr(estado_t(0,a));

      e_trans.insert_tr(std::pair<char,std::string>(con[0],a));
      Nfa_.update_estado(it,e_trans);
      getline(FileIn_, word);
    }
    reader.a_state = true;
  }
  else {
    getline(FileIn_, word);
  }
}













