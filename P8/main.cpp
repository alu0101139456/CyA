#include <iostream>
// #include "cfg_t.hpp"
#include "CFG2NFA_t.hpp"

int main(int argc, char * argv[]){

  if( argc == 3){
    CFG2NFA_t cfg_to_nfa(argv[1], argv[2]);
    cfg_to_nfa.convert_to_nfa();
    cfg_to_nfa.print_nfa_to_file();

  }

  return 0;
}
