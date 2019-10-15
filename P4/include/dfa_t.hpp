#pragma once

#include<iostream>
#include<fstream>
#include "alfabeto_t.hpp"

class automata_t {
 private:
  std::ifstream fileIn_;
  alfabeto_t Al_;
 public:
  automata_t() {};
   ~automata_t() {}

   automata_t(std::string aux, alfabeto_t Al);

   bool compara( int aux);

 private:
   void read_file();
};
