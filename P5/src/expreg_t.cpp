/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶¶
 * Autor: Ángel Julián Bolaño Campos                                          *¶
 * Asignatura: Computabilidad y Algoritmia                                    *¶
 * Curso: 2º Ingeniería Informática                                           *¶
 * Editor: VIM                                                                *¶
 * Estilo Google C++ Style Guide                                              *¶
 * Práctica 5: Expresiones regulares                                          *
 * ****************************************************************************/
//                              EXPREG_T.CPP
#include "../include/expreg_t.hpp"


expreg_t::expreg_t(std::string expresion, alfabeto_t alfa, unsigned formato):
expre_(expresion),
alfa_(alfa),
formato_(formato){
 if (alfa_.is_in_alphabet(expre_)) {  //Se comprueba que todos los caracteres
                                       //pertenecen al alfabeto
    //ex_pf_ = convert_to_posfija(convert());
    expre_ = convert();
    ex_pf_ = convert_to_posfija();
    std::cout << expre_ << '\n' << ex_pf_ << '\n';
  }
  else
    std::cerr << "Hay caracteres que no pertenecen al alfabeto establecido\n";
}

expreg_t::expreg_t(const expreg_t& rhs) {
  this->alfa_ = rhs.alfa_;
  this->formato_ = rhs.formato_;
  this->expre_ = rhs.expre_;
  this->ex_pf_ = rhs.ex_pf_;
  this->pila_ = rhs.pila_;
}


std::string expreg_t::convert_to_posfija() {
  std::string ex_pf;
  for(size_t i=0; i < expre_.size(); i++) {
    caracter_t aux = alfa_.find(expre_[i]);
    if(aux.is_ParAb()) {
      pila_.push(aux);
    }
    else if(aux.is_operando()) {
      ex_pf.push_back(aux.get_caracter());
      v_posfija_.push_back(aux);
    }
    else
      check(ex_pf, aux);
  }
  while ( !pila_.empty()) {
    ex_pf.push_back(pila_.top().get_caracter());
    v_posfija_.push_back(pila_.top());
    pila_.pop();
  }
  return ex_pf;
}

void expreg_t::check(std::string& ex_pf, caracter_t& aux) {
  if(pila_.empty() || pila_.top().is_ParAb()) {
      pila_.push(aux);
    }
    else if(aux.is_ParCe()) {
      while (!pila_.top().is_ParAb()) {
        ex_pf.push_back(pila_.top().get_caracter());
        v_posfija_.push_back(pila_.top());
        pila_.pop();
      }
      pila_.pop();
    }
    else if( aux.get_prioridad() > pila_.top().get_prioridad()) {
      pila_.push(aux);
    }
    else if(aux.get_prioridad() == pila_.top().get_prioridad()) {
      ex_pf.push_back(pila_.top().get_caracter());
      v_posfija_.push_back(pila_.top());
      pila_.pop();
      pila_.push(aux);
    }
    else {
      ex_pf.push_back(pila_.top().get_caracter());
      v_posfija_.push_back(pila_.top());
      pila_.pop();
      check(ex_pf, aux);
    }

}

std::vector<caracter_t> expreg_t::get_posfija() {
  return v_posfija_;
}

void expreg_t::set_vector_sufijo(std::vector<caracter_t> aux) {
  v_sufija_ = aux;

}

void expreg_t::set_vector_posfijo(std::vector<caracter_t> aux) {
  v_posfija_ = aux;

}

void expreg_t::set_vector_infijo(std::vector<caracter_t> aux) {
  v_expresion_ = aux;

}



expreg_t& expreg_t::operator=(const expreg_t& rhs) {
  this->alfa_ = rhs.alfa_;
  this->formato_ = rhs.formato_;
  this->expre_ = rhs.expre_;
  this->ex_pf_ = rhs.ex_pf_;
  this->pila_ = rhs.pila_;
  return *this;
}


//Convierte el string leido y añade entre dos operandos el caracter &
std::string expreg_t::convert() {
  std::string string_final;
  caracter_t previo = alfa_.find(expre_[0]);
  string_final.push_back(expre_[0]);
  for(size_t i=1; i < expre_.size(); i++) {
    caracter_t aux = alfa_.find(expre_[i]);
    if( previo.is_operando() && aux.is_operando() ){
      string_final.push_back('&');
      string_final.push_back(aux.get_caracter());
    }
    else if( previo.is_ParAb() && aux.is_operando()) {
      string_final.push_back(aux.get_caracter());
    }
    else if( previo.is_operando() && aux.is_operador() &&
        previo.get_caracter() != '*') {

      string_final.push_back(aux.get_caracter());
    }
    else if( previo.is_operador() && aux.is_operando() &&
        previo.get_caracter() != '*'){
      string_final.push_back(aux.get_caracter());
    }
    else if( previo.is_operando() && aux.is_ParCe()) {
      string_final.push_back(aux.get_caracter());
    }
    else if( previo.is_ParCe() && aux.get_caracter() == '*') {
      string_final.push_back(aux.get_caracter());
    }
    else if((previo.get_caracter() == '*') &&  (aux.is_operando()) ) {
      string_final.push_back('&');
      string_final.push_back(aux.get_caracter());
    }
    else if( previo.is_ParCe() && aux.is_ParAb() ) {
      string_final.push_back('&');
      string_final.push_back(aux.get_caracter());
    }
    previo = aux;
  }
  //std::cout << "String de entrada: " << expre_ << "\nString de salida: " <<
  //  string_final << std::endl;
  return string_final;
}













