#include "CFG2NFA_t.hpp"

CFG2NFA_t::CFG2NFA_t(std::string infile, std::string outfile): cfg_(infile){}



void CFG2NFA_t::print_grammar(){ cfg_.convert_to_nfa(); cfg_.print();}
void CFG2NFA_t::print_autommata(){}
