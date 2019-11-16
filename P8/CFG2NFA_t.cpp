#include "CFG2NFA_t.hpp"

CFG2NFA_t::CFG2NFA_t(std::string infile, std::string outfile): cfg_(infile), out_file_(outfile){}



void CFG2NFA_t::print_grammar(){  cfg_.print();}
void CFG2NFA_t::print_autommata(){}
void CFG2NFA_t::convert_to_nfa(){ nfa_ = cfg_.convert_to_nfa();}
void CFG2NFA_t::print_nfa_to_file(){nfa_.print_file_out(out_file_);}
