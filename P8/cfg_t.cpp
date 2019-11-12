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
    file_in.close();
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
