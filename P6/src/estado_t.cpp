

#include "../include/estado_t.hpp"

void estado_t::clean() {
  id_ = 0;
  name_.clear();
  acept_= false;
  arranque = false;
  trans_map aux;
  transiciones_ = aux;
}


void estado_t::insert_tr (std::pair<char, std::string> aux) {


}
