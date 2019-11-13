








#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "cfg_t.hpp"
#include "nfa_t.hpp"

class CFG2NFA_t {
 private:
  cfg_t cfg_;
  nfa_t nfa_;
  std::string out_file_;

 public:
  CFG2NFA_t(){}
  CFG2NFA_t(std::string infile, std::string outfile);
  ~CFG2NFA_t(){}

  // nfa_& convert_cfg_to_nfa();

  void print_grammar();
  void print_autommata();
  void convert_to_nfa();
  void print_nfa_to_file();
};
