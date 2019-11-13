/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 7: Construcción de Subconjuntos                                   *
 ****************************************************************************/
//                                nfa_t.hpp
#include "nfa_t.hpp"

nfa_t::nfa_t(const nfa_t& rhs){
  *this = rhs;
}


void nfa_t::print_file_out(std::string namefile) {
  std::cout << "\n\nOpening file: " << namefile << '\n';
  std::ofstream fo(namefile);
  if(fo.is_open()){
    std::cout << "alfabeto: " << alpha.size() << '\n';
    fo <<  alpha.size() << '\n';
    for(auto it= alpha.begin(); it != alpha.end(); ++it){
      fo << it->get_caracter() << '\n';
    }
    fo << estados_.size() << '\n';
    int nAcept = 0;
    int nTrans = 0;
    std::queue<std::string> acept_states;
    std::queue<std::string> transitions;
    for(auto it = estados_.begin(); it != estados_.end(); ++it) {
      fo << it->get_name() << '\n';
      if( it->get_acept() ){
        acept_states.push(it->get_name());
        nAcept++;
      }
      nTrans += it->get_n_trans() + it->get_n_e_trans();
      for(auto itTrans = it->get_tran().begin(); itTrans != it->get_tran().end(); ++itTrans){
        for(auto itSt = itTrans->second.begin(); itSt != itTrans->second.end(); ++itSt){
          std::string trans = it->get_name() +
                              " " +
                              std::string(1,itTrans->first) +
                              " " +
                              itSt->get_name();
          transitions.push(trans);
        }
      }
      for(auto itEt = it->get_eps_begin(); itEt != it->get_eps_end(); ++itEt){
        std::string trans = it->get_name() +
                            " ~ " +
                            itEt->get_name();
        transitions.push(trans);
      }
    }
    fo << arranque_.get_name() << '\n';
    fo << nAcept << '\n';
    while(!acept_states.empty()){
      fo << acept_states.front() << '\n';
      acept_states.pop();
    }
    fo << nTrans << '\n';
    while(!transitions.empty()){
      fo << transitions.front() << '\n';
      transitions.pop();
    }
    fo.close();
  }
  else
    std::cout << "No se pudo abrir e fichero\n";
}



void nfa_t::insert_estado(estado_t estado) {
  estados_.insert(estado);
  if(estado.is_arranque())
    arranque_ = estado;
}

std::set<estado_t> nfa_t::e_clausura(const std::set<estado_t>& T) {
  std::stack<estado_t> pila_estados;
  for(auto it=T.begin(); it != T.end(); ++it) {
    std::cout << "iter\n";
    if(it->get_name() != "Muerte"){
      pila_estados.push(*estados_.find(*it));
    }
  }

  std::cout << "Estados insertados\n";
  std::set<estado_t> e_clausura = T;
  while (!pila_estados.empty()) {
    estado_t temp = pila_estados.top();
    pila_estados.pop();
    for( auto it=temp.get_eps_begin(); it != temp.get_eps_end(); ++it) {
      if(e_clausura.insert(*estados_.find(*it)).second) //Insert devuelve true o false si el
                                        //elemento ya estaba en el set
        pila_estados.push(*estados_.find(*it));
    }
  }
  std::cout << "Eclausura {";
  for(auto it = e_clausura.begin(); it != e_clausura.end(); ++it ){
    std::cout << it->get_name() << ',';
  }
  std::cout << "}\n ";
  return e_clausura;
}


std::set<estado_t>::iterator nfa_t::find_estado(std::string& name){
  std::set<estado_t>::iterator it;
  for(it = estados_.begin(); it != estados_.end(); ++it) {
     if(it->get_name() == name ) return it;
  }
  return it;
}

void nfa_t::update_estado(std::set<estado_t>::iterator& it,const estado_t& nuevo) {
  if (it != estados_.end()) {
    estados_.erase(it);
    estados_.insert(nuevo);
  }
}

std::set<estado_t>::iterator nfa_t::begin() {
  return estados_.begin();
}

std::set<estado_t>::iterator nfa_t::end() {
  return estados_.end();
}

std::vector<std::string> nfa_t::get_est_acept() {
  std::vector<std::string> aux;
  for(auto it=estados_.begin() ; it != estados_.end(); ++it) {
    if(it->get_acept())
      aux.push_back("\""+it->get_name()+"\"");
  }
  return aux;
}

std::string nfa_t::get_est_arranque_p() {
  auto it = estados_.end();
  for(it=estados_.begin() ; it != estados_.end(); ++it) {
    if(it->is_arranque())
      return ("\""+it->get_name()+"\"");
  }
  return "none";
}

estado_t nfa_t::get_est_arranque() {
auto it = estados_.end();
  for(it=estados_.begin() ; it != estados_.end(); ++it) {
    if(it->is_arranque())
      return (*it);
  }
  return *it;
}

void nfa_t::print() {
  std::cout << "\n\nPrinting NFA\n";
  std::cout << "States:\n{";
  for(auto it = estados_.begin(); it != estados_.end(); ++it)
    std::cout <<  '(' << it->get_name() << ',' << it->is_arranque() << ',' << it->get_acept() << "),";
  std::cout << '\n';
  for(auto it = estados_.begin(); it != estados_.end(); ++it){
    for(auto it2 = it->get_tran().begin(); it2 != it->get_tran().end(); ++it2){
      for(auto it3 = it2->second.begin(); it3 != it2->second.end(); ++it3){
        std::cout << it->get_name() << " " << it2->first << " " << it3->get_name() << '\n';
      }
    }
    for(auto it2 = it->get_eps_begin(); it2 != it->get_eps_end(); ++it2){
      std::cout << it->get_name() << " ~ " << it2->get_name() << '\n';
    }

  }
  std::cout << "\n\n";
}

void nfa_t::print_ini() {
  std::cout << "Entro en print_ini\n";
  std::set<estado_t> aux;
  get_est_arranque().print(aux);
}

dfa_t nfa_t::convert_to_dfa(){
  dfa_t dfa;
  std::string st_name = "A";
  st_name[0]--;

  // std::cout << "Estado de muerte\n"; //DEBUG
  std::set<estado_t> death;
  estado_t d_st("Muerte");
  for(auto itA = alpha.begin(); itA != alpha.end(); ++itA){
    if(itA->get_caracter() != '~')
      d_st.insert_tr(itA->get_caracter(), d_st);
  }
  death.insert(d_st);

  std::map<con_est_t, std::map<char, con_est_t>> trans_dfa;
  std::set<con_est_t> marcados;
  std::set<estado_t> setInicial;
  setInicial.insert(get_est_arranque());
  con_est_t S("S", e_clausura(setInicial));
  std::set<con_est_t> DFA_st;
  std::vector<con_est_t> checklist;
  checklist.push_back(S);
  DFA_st.insert(S);

  int i = 0;
  while(i < checklist.size() && marcados.find(checklist[i]) == marcados.end()){
    // std::cout << "Iterating " << checklist[i].get_name() << '\n'; //DEBUG
    marcados.insert(checklist[i]);
    std::map<char, con_est_t> mapa_aux;
    for(auto itAlf = alpha.begin(); itAlf != alpha.end(); ++itAlf){
      if(itAlf->get_caracter() != '~'){
        // std::cout << "Checking transition\n"; //DEBUG
        std::set<estado_t> new_st = checklist[i].move(itAlf->get_caracter());
        std::set<estado_t> new_set;
        // std::cout << "New set created with transition\n"; //DEBUG
        con_est_t conj_estado;
        if(new_st.empty()){
          conj_estado = con_est_t("Death", death);
        }
        else {
          // std::cout << "llamando a eclausura\n"; //DEBUG
          for(auto it = new_st.begin(); it != new_st.end(); ++it){
            if(it->get_name() == "Muerte")
              new_set.insert(*it);
            else
              new_set.insert(*estados_.find(*it));
              st_name[0]++;
          }
          std::set <estado_t> clausura = e_clausura(new_set);
          if(clausura != death)
            conj_estado = con_est_t(st_name, clausura);
          else
            conj_estado = con_est_t("Death", death);
        }
        auto itR = pertenece(conj_estado, DFA_st);
        if(itR == DFA_st.end()){
          // std::cout << "Insertando en el DFA\n"; //DEBUG
          DFA_st.insert(conj_estado);
          checklist.push_back(conj_estado);
          mapa_aux[itAlf->get_caracter()] = conj_estado;
        }
        else{
          mapa_aux[itAlf->get_caracter()] = *itR;
        }


        // std::cout << "\n\n"; //DEBUG
      }
    }
    trans_dfa[checklist[i]] = mapa_aux;
    ++i;
  }
  // std::cout << "Contrucción de subconjuntos\n"; //DEBUG
  // Build dfa with data sets information
  for(auto itSt = DFA_st.begin(); itSt != DFA_st.end(); ++itSt){
    estado_t est(itSt->get_name());
    for (auto itAlph = alpha.begin(); itAlph != alpha.end(); ++itAlph){
      if (itAlph->get_caracter() != '~'){
        // std::cout << itAlph->get_caracter() << '\n'; //DEBUG
        // if(trans_dfa.find(*itSt) != trans_dfa.end()){
        estado_t destino(trans_dfa.at(*itSt).at(itAlph->get_caracter()).get_name());
        // std::cout << destino.get_name() << '\n'; //DEBUG
        est.insert_tr(itAlph->get_caracter(), destino);
        // }
      }

    }
    dfa.insert_estado(est);
  }
  return dfa;
  // dfa.print();

}

std::set<con_est_t>::iterator nfa_t::pertenece(const con_est_t& a,
                                               const std::set<con_est_t>&b){

  for(auto it = b.begin(); it != b.end(); ++it){
    if(a == *it)
      return it;
  }
  return b.end();
}

nfa_t& nfa_t::operator=(const nfa_t& rhs){
  this->estados_  = rhs.estados_;
  this->alpha     = rhs.alpha;
  this->arranque_ = rhs.arranque_;
  return *this;
}
