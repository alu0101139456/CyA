


#include<iostream>
#include "caracter_t.hpp"


class nodo_t {
 private:
  caracter_t valor_;
  nodo_t* n_izq_= nullptr;
  nodo_t* n_der_= nullptr;
  bool nodoHoja_ =false;

 public:
  nodo_t() {}
  ~nodo_t();
  nodo_t(caracter_t val);
//getter
  caracter_t get_val();
  nodo_t* get_n_izq();
  nodo_t* get_n_der();
  bool get_modo();
  //setter
  void set_valor( caracter_t val);
  void set_nodo_izq( nodo_t* n_izq);
  void set_nodo_der( nodo_t* n_der);
  //delete 1º izq
  //       2º derecha

};




//Te quedaste sin bateria?
