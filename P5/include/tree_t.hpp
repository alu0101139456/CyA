#pragma once

#include<iostream>
#include "expreg_t.hpp"
#include "nodo_t.hpp"
#include<stack>


class tree_t {
 private:
  expreg_t expresion_;
  nodo_t* raiz_;
  unsigned size_;
   
 public:
   tree_t() {}
  ~tree_t() { /*delete raiz_;*/}
   tree_t(expreg_t exp);

  void recorrido_posfija();
  void recorrido_infija();
  void recorrido_sufija();

  

  unsigned get_size() {return size_; }
 private:
  void r_sufija( nodo_t* ini, std::vector<caracter_t>& vs);
  void r_posfija( nodo_t* ini, std::vector<caracter_t>& vs);
  void r_infija( nodo_t* ini, std::vector<caracter_t>& vs);




};
