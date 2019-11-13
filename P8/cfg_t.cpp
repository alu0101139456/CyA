#include "cfg_t.hpp"

cfg_t::cfg_t(std::string file_name){
  //lectura de fichero
  std::ifstream  file_in(file_name);
  checker reader;
  int n_alpha = 0, n_symbols = 0, n_prod = 0;
  std::string delimiter = " ";
  int pos = 0;
  if(file_in.is_open()){
    alfabeto_.insert(symbol_t('~', true));
    std::string read_line;
    while(getline(file_in, read_line)){
      if( read_line.length() < 2 || (read_line[0] != '/') || (read_line[1] != '/')) {
        if(!reader.alpha.first){
          if(reader.alpha.second == 0){
            // std::cout << "Reading alphabet " << read_line << "\n"; //DEBUG
            reader.alpha.second = stoi(read_line);
          }
          else{
            alfabeto_.insert(symbol_t(read_line[0], true));
            n_alpha++;
            if (reader.alpha.second == n_alpha)
              reader.alpha.first = true;
          }
        }
        else if (!reader.symbols.first){
          if(reader.symbols.second == 0){
            // std::cout << "Reading symbols " << read_line << "\n"; //DEBUG
            reader.symbols.second = stoi(read_line);
          }
          else {
            no_terminal_.insert(symbol_t(read_line[0], false));
            n_symbols++;
            if (reader.symbols.second == n_symbols)
              reader.symbols.first = true;
          }
        }
        else if(!reader.start){
          // std::cout << "Reading start: " << read_line << '\n'; //DEBUG
          arranque_ = symbol_t(read_line[0],false);
          reader.start = true;
        }
        else if(!reader.productions.first){
          if(reader.productions.second == 0){
            // std::cout << "Reading productions " << read_line << "\n"; //DEBUG
            reader.productions.second = stoi(read_line);
          }
          else {
            symbol_t desde(read_line[0], false);
            pos = read_line.find(delimiter);
            read_line.erase(0, pos + 1);
            pos = read_line.find(delimiter);
            read_line.erase(0, pos + 1);
            cadena_t a;
            for(int i = 0; i < read_line.size(); i++){
              symbol_t aux(read_line[i], false);
              auto it = alfabeto_.find(aux);
              if (it != alfabeto_.end()){
                a.append(*it);
              }
              else {
                auto it2 = no_terminal_.find(aux);
                if(it2 != no_terminal_.end())
                  a.append(*it2);
                else
                  std::cout << "simbolo no encontrado\n";
              }
            }
            if (producciones_.find(desde) == producciones_.end()){
              std::set<cadena_t> new_chain;
              new_chain.insert(a);
              producciones_.insert(std::make_pair(desde, new_chain));
            }
            else {
              std::set<cadena_t>& tmp = producciones_[desde];
              tmp.insert(a);
            }
            n_prod++;
            if(reader.productions.second == n_prod){
              reader.productions.first = true;
            }

          }

        }
      }
    }
    std::cout << "File read\n";
    file_in.close();
  }
}

std::set<symbol_t>& cfg_t::get_alfabeto(){
  return alfabeto_;
}

std::set<symbol_t>& cfg_t::get_no_terminal(){
  return no_terminal_;
}

produccion_t& cfg_t::get_producciones(){
  return producciones_;
}

symbol_t& cfg_t::get_arranque(){
  return arranque_;
}

nfa_t cfg_t::convert_to_nfa(){
  nfa_t nfa;
  int count = 0;
  estado_t aceptacion("Vf");
  aceptacion.set_acept(true);
  nfa.insert_estado(aceptacion);
  alfabeto_t alf;
  for(auto it = alfabeto_.begin(); it != alfabeto_.end(); ++it){
    // std::cout << "Iterating\n";
    alf.insert_symbol(it->get_name());
  }
  nfa.set_alpha(alf);
  for(auto it = no_terminal_.begin(); it != no_terminal_.end(); ++it){

    // std::cout << "estado: " << it->get_name() << std::endl; //DEBUG
    estado_t new_st(std::string(1,it->get_name()));
    if(*it == arranque_)
      new_st.set_arranque(true);
    nfa.insert_estado(new_st);
  }

  /* DEBUG
  for(auto it = nfa.begin(); it != nfa.end(); ++it){
    std::cout << it->get_name() << ',';
  }
  std::cout << "\nInserted states\n";
  */
  for(auto it = producciones_.begin(); it != producciones_.end(); ++it){
    // std::cout << "Outermost loop\n"; //DEBUG
    for(auto it2 = it->second.begin(); it2 != it->second.end(); ++it2){
      // std::cout << "Innermost loop\n"; //DEBUG
      std::string origen = std::string(1, it->first.get_name());
      // std::cout << "Origen: " << origen << '\n'; //DEBUG
      auto itOrigen = nfa.find_estado(origen);
      estado_t origenAux = *itOrigen;
      if(it2->get_cadena().size() >= 2){
        // std::cout << "Chain is bigger than 2\n"; //DEBUG
        /*create_chain(nfa,
                     it2->get_cadena().size() - 1,
                     std::string(1, it->first.get_name()),
                     it2->get_name(),
                     count,
                     origenAux,
                     itOrigen
                   );*/

        // std::cout << "Siize: " << (it2->get_cadena().size() - 2 + it2->is_terminal()) << '\n';
        for(int i = 0; i < (it2->get_cadena().size() - 2 + it2->is_terminal()); i++){
          // std::cout << "Building intermediate state\n"; //DEBUG
          std::string aux_name = std::string(1,it->first.get_name()) + std::to_string(count);
          estado_t new_st(aux_name);
          nfa.insert_estado(new_st);
          count++;
        }

        // std::cout << "Inserted extra states\n"; //DEBUG
        for(int i = 0; i < (it2->get_cadena().size() - 2 + it2->is_terminal()); i++){
          char caracter = it2->get_cadena()[i].get_name();
          std::string destino = std::string(1,it->first.get_name()) +\
                                std::to_string(count - (it2->get_cadena().size() - 2 + it2->is_terminal()) + i);
          estado_t dest(destino);
          origenAux.insert_tr(caracter, dest);
          nfa.update_estado(itOrigen, origenAux);
          itOrigen = nfa.find_estado(destino);
          origenAux = *itOrigen;

        }
        // std::cout << "Updated nfa"; //DEBUG
      }

      // std::cout << "Chain is smaller than 2\n"; //DEBUG
      if(it2->is_terminal()){
        // std::cout << "Adding e_trans\n"; //DEBUG
        if(it2->get_cadena()[it2->get_cadena().size()-1].get_name() == '~')
          origenAux.insert_e_tr(aceptacion);
        else
          origenAux.insert_tr(it2->get_cadena()[it2->get_cadena().size() - 1].get_name(), aceptacion);
        nfa.update_estado(itOrigen, origenAux);
      }
      else{
        std::string destino = std::string(1,no_terminal_.find(symbol_t(it2->get_cadena()[it2->get_cadena().size() - 1].get_name(), false))->get_name());
        estado_t dest(destino);
        origenAux.insert_tr(it2->get_cadena()[it2->get_cadena().size() - 2].get_name(), dest);
        nfa.update_estado(itOrigen, origenAux);
      }
    }
  }
  // nfa.print();
  // nfa.set_alpha(alf);
  // nfa.convert_to_dfa();
  return nfa;
}

void cfg_t::print_nfa(){
  // nfa_t nfa;
  /*for(auto it = no_terminal.begin(); it != no_terminal_.end(); ++it){
    nfa.insert_estado(estado_t(it->get_name()));
  }*/
  for(auto it = producciones_.begin(); it != producciones_.end(); ++it){
    // transicion_t trans;
    for(auto it2 = it->second.begin(); it2 != it->second.end(); ++it2){
      /*for(int i = 0; i < (it2->get_cadena().size() - 1); i++){
        std::string aux_name = it->first.get_name() + i;
        nfa_.insert_estado(estado_t(it->get_name()));
      }*/

      std::string origen = std::string(1, it->first.get_name());
      if(it2->get_cadena().size() >= 2){
        for(int i = 0; i < (it2->get_cadena().size() - 2); i++){
          char caracter = it2->get_cadena()[i].get_name();
          std::string destino = std::string(1,it->first.get_name()) + std::to_string(i);
          // std::cout << origen << " " << caracter << " " << destino << '\n';// DEBUG
          origen = destino;
        }
        // std::cout << origen << " " << it2->get_cadena()[it2->get_cadena().size() - 2].get_name();// DEBUG
      }

      // if(it2->is_terminal())
        // std::cout << origen << " Vf\n";// DEBUG
      // else
        // std::cout << " " <<no_terminal_.find(symbol_t(it2->get_cadena()[it2->get_cadena().size() - 1].get_name(), false))->get_name() << '\n';//DEBUG

    }
  }
}

void cfg_t::print(){
  std::cout << "V = {";
  for(auto it = no_terminal_.begin(); it != no_terminal_.end(); ++it){
    std::cout << it->get_name() << ',';
  }
  std::cout << "}\n";
  std::cout << "Alph = {";
  for(auto it = alfabeto_.begin(); it != alfabeto_.end(); ++it){
    std::cout << it->get_name() << ',';
  }
  std::cout << "}\n";
  std::cout << "Arranque: " << arranque_.get_name() << '\n';
  for(auto it = producciones_.begin(); it != producciones_.end(); ++it){
    for (auto it2 = it->second.begin(); it2 != it->second.end(); it2++) {
      std::cout << it->first.get_name() << " -> " << it2->get_name() << '\n';
    }
  }
}

// nfa_t cfg_t::convert_to_nfa();

void cfg_t::create_chain(nfa_t& nfa,
                         int nSteps,
                         std::string st_name,
                         std::string cadena,
                         int& count,
                         estado_t& origenAux,
                         std::set<estado_t>::iterator itOrigen
                        ){

  for(int i = 0; i < nSteps; i++){
    std::string aux_name = st_name + std::to_string(count);
    estado_t new_st(aux_name);
    nfa.insert_estado(new_st);
  }

  for(int i = 0; i < nSteps; i++){
    char caracter = cadena[i];
    std::string destino = st_name + std::to_string(count - nSteps + i);
    estado_t dest(destino);
    origenAux.insert_tr(caracter, dest);
    nfa.update_estado(itOrigen, origenAux);
    itOrigen = nfa.find_estado(destino);
    origenAux = *itOrigen;
  }
}
