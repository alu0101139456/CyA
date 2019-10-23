


#include "../include/tree_t.hpp"


tree_t::tree_t(expreg_t exp) {
  std::stack<nodo_t *> pila;
  std::vector<caracter_t> vposf = exp.get_posfija();

  for(size_t i=0; i < vposf.size(); i++) {  
    nodo_t * newNode = new nodo_t(vposf[i]);
    size_++;
    if(vposf[i].is_operador()) {
      nodo_t * A = pila.top();
      pila.pop();
      if(vposf[i].get_ari() == UNARIO) {
        newNode->set_nodo_izq(A);
      }
      else {
        nodo_t * B = pila.top();
        pila.pop();
        newNode->set_nodo_der(A);
        newNode->set_nodo_izq(B);
      }
    }
    pila.push(newNode);
  }
  raiz_ = pila.top();
  pila.pop();

}


void tree_t::r_sufija(nodo_t* ini, std::vector<caracter_t>& vs) { 
  if(ini != nullptr) {
    vs.push_back(ini->get_val());
    r_sufija(ini->get_n_izq(), vs);
    r_sufija(ini->get_n_der(), vs);
  }
}

void tree_t::recorrido_sufija(std::ofstream& os) {
  std::vector<caracter_t> vs;
  r_sufija(raiz_, vs);
  expresion_.set_vector_sufijo(vs);

  for(size_t i=0;i < vs.size(); i++) {
    os << vs[i].get_caracter();
  }
  os << "          ";

}

void tree_t::recorrido_posfija(std::ofstream& os){
  std::vector<caracter_t> vs;
  r_posfija(raiz_, vs);
  expresion_.set_vector_posfijo(vs);

  for(size_t i=0;i < vs.size(); i++) {
    os << vs[i].get_caracter();
  }
  os << "          ";
}

void tree_t::r_posfija(nodo_t* ini, std::vector<caracter_t>& vs){
  if(ini != nullptr) {
    r_posfija(ini->get_n_izq(), vs);
    r_posfija(ini->get_n_der(), vs);
    vs.push_back(ini->get_val());
  }
}

 void tree_t::recorrido_infija(std::ofstream& os) {
  std::vector<caracter_t> vs;
  r_infija(raiz_, vs);
  expresion_.set_vector_infijo(vs);

  for(size_t i=0;i < vs.size(); i++) {
    os << vs[i].get_caracter();
  }
  os << "          ";
}

void tree_t::r_infija(nodo_t* ini, std::vector<caracter_t>& vs){
  if(ini != nullptr){
    if(ini->get_val().is_operador()){
      vs.push_back(caracter_t('(', 0,0,0));
    }
    r_infija(ini->get_n_izq(), vs);
    vs.push_back(ini->get_val());
    r_infija(ini->get_n_der(), vs);
    if(ini->get_val().is_operador()) {
      vs.push_back(caracter_t(')',0,0,0));
    }
  }
}

void tree_t::print_in_file(std::ofstream& fileout) {
  fileout << "Infija: ";
  recorrido_infija(fileout);
  fileout << "Posfija: ";
  recorrido_posfija(fileout);
  fileout << "Prefija: ";
  recorrido_sufija(fileout);
  fileout << '\n';

}
