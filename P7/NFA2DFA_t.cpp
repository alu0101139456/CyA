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
  std::cout << "Reading file \n";
  read_file();
  std::cout << "File read\n";
  if(FileIn_.is_open()) FileIn_.close();
  if(FileOut_.is_open())FileOut_.close();
  //convert_to_dfa();
  //Dfa_.print();
}

dfa_t nfa2dfa_t::convert_to_dfa(){
 std::string st_name= "A";
  std::map<con_est_t,std::map<char,con_est_t>> trans_dfa;
  std::set<con_est_t> marcados;
  std::set<estado_t> aux; aux.insert(Nfa_.get_est_arranque());
  con_est_t S("S", Nfa_.e_clausura(aux));
  std::set<con_est_t> DFA_st; DFA_st.insert(S);
  auto itT = DFA_st.begin();
  std::cout << "starting iterations \n";
  while(itT != DFA_st.end() && marcados.find(*itT) == marcados.end() ){
    std::cout << "Iterating \n";
    marcados.insert(*itT);
    std::map<char, con_est_t> mapa_aux;
    for(auto itAlf = alpha.begin(); itAlf != alpha.end(); ++itAlf){
      if(itAlf->get_caracter() != '~'){
        con_est_t R(st_name, Nfa_.e_clausura(itT->move(itAlf->get_caracter())));
        auto itR = pertenece(R, DFA_st);
        if( itR == DFA_st.end()){
          std::cout << "Inserting value on DFA_st\n";
          DFA_st.insert(R);
          itR = DFA_st.find(R);
        }
        std::cout << "creating entry\n";
        mapa_aux[itAlf->get_caracter()] = *itR;
        st_name[0]++;
      }
    }
    trans_dfa[*itT] = mapa_aux;
    std::cout << "Adding entry\n";
    ++itT;
    std::cout << "End of iteration\n";
  }
  std::cout << "End of while\n";
  for(auto it = DFA_st.begin(); it != DFA_st.end(); ++it){
    estado_t est(0, it->get_name());
    for (auto it2 = alpha .begin(); it2 != alpha.end(); it2++) {
      if (it2->get_caracter() != '~'){
        if(trans_dfa.find(*it) != trans_dfa.end()){
          estado_t destino(0,trans_dfa.at(*it).at(it2->get_caracter()).get_name());
          est.insert_tr(it2->get_caracter(), destino);
        }
      }
    Dfa_.insert_estado(est);
    }
  }
  return Dfa_;
}

std::set<con_est_t>::iterator nfa2dfa_t::pertenece(const con_est_t& a,
                                                   const std::set<con_est_t>&b){

  for(auto it = b.begin(); it != b.end(); ++it){
    if(a == *it)
      return it;
  }
  return b.end();
}


void nfa2dfa_t::read_file() {
  std::string aux;
  if(FileIn_.is_open()) {
    while(getline(FileIn_, aux)) {
      if( aux.length() >= 2 && (aux[0] == '/') && (aux[1] == '/')) {
        FileOut_ << aux << '\n';
      }
      else {
        if(!reader.alpha)
          read_alpha_from_file(aux);
        else if (!reader.states)
          read_states_from_file(aux);
        else if (!reader.start)
          read_start_state_from_file(aux);
        else if(!reader.a_state)
          read_acept_states_from_file(aux);
        else if(!reader.transitions)
          read_transitions_from_file(aux);
      }
    }
  }
  else { std::cerr << "ATENCIÓN: Error en lectura de fichero de entrada\n";}
}


void nfa2dfa_t::read_alpha_from_file(std::string& word) {
  if(reader.alpha == false) {
    int n_alpha = stoi(word);
    for(int i = 0; i < n_alpha; i++) {
      getline(FileIn_, word);
      alpha.insert_symbol(word[0]);
    }
    reader.alpha = true;
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
}

void nfa2dfa_t::read_start_state_from_file(std::string& word) {
  if(reader.start == false) {
    estado_t start_state;
    auto it = Nfa_.find_estado(word);
    start_state = *it;
    start_state.set_arranque(true);
    Nfa_.update_estado(it, start_state);
    reader.start = true;
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
}

void nfa2dfa_t::read_transitions_from_file(std::string& word) {
  if(reader.transitions == false) {
    int pos=0;
    std::string delimiter = " ";
    int n_trans = stoi(word);
    for(int i=0; i < n_trans ; i++) {
      getline(FileIn_, word);
      pos = word.find(delimiter);
      std::string desde = word.substr(0,pos);
      word.erase(0, pos + 1);
      pos = word.find(delimiter);
      std::string con = word.substr(0,pos);
      pos = word.find(delimiter);
      word.erase(0, pos + 1);
      std::string a = word.substr(0, word.size());
      word.erase(0, word.size() -1);
      //creo estado
      auto it = Nfa_.find_estado(desde);
      estado_t origen = *it;
      estado_t destino = *Nfa_.find_estado(a);
      if( con == "~") origen.insert_e_tr(destino);
      else origen.insert_tr(con[0],destino);
      Nfa_.update_estado(it,origen);
    }
    reader.transitions = true;

  }
}












