

#include "estado_t.hpp"

void estado_t::clean() {
  id_ = 0;
  name_.clear();
  acept_= false;
  arranque = false;
  trans_map aux;
  transiciones_ = aux;
}



