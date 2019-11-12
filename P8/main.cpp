#include <iostream>
#include "cfg_t.hpp"

int main(int argc, char * argv[]){

  if( argc == 2){
    cfg_t cfg(argv[1]);
    cfg.print();

  }

  return 0;
}
