/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 3: Calculadora de lenguajes formales                              *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
//calculadora_t.cpp
//
#include "../include/calculadora_t.hpp"


calculadora_t::calculadora_t(std::string in, std::string out, std::string option) {
  fileIn_ = std::ifstream(in);
  fileOut_ = std::ofstream(out);
  op_ = std::stoi(option);
  if (!read_file())
    std::cout << "Error de lectura en fichero\n";
  else {
    for (size_t i=0; i < lenguajes_.size(); i+=2) {
      operate(lenguajes_[i], lenguajes_[i+1]);
    }

  }
 // write_in_file( lenguajes_[0]);
 // write_in_file( lenguajes_[1]);
 // fileOut_ << "Concatenación\n";
 // lenguaje_t aux = concatena(lenguajes_[0], lenguajes_[1]);
 // write_in_file(aux);
 // fileOut_ << "Unión\n";
 // aux = uniones(lenguajes_[0], lenguajes_[1]);
 // write_in_file(aux);
 // fileOut_ << "Interseccion\n";
 // aux = interseccion(lenguajes_[0], lenguajes_[1]);
 // write_in_file(aux);
 // fileOut_ << "Diferencia\n";
 // aux = diferencia(lenguajes_[0], lenguajes_[1]);
 // write_in_file(aux);
 // fileOut_ << "Sublenguaje\n";
 // sublenguaje(lenguajes_[0], lenguajes_[1])? fileOut_ << "TRUE\n" :
 //                                            fileOut_ << "FALSE\n";
 // fileOut_ << "Igual\n";
 // igual(lenguajes_[0], lenguajes_[1])? fileOut_ << "TRUE\n" :
 //                                      fileOut_ << "FALSE\n";
 // write_in_file( potencia(lenguajes_[1], 0));
 // write_in_file( potencia(lenguajes_[1], 1));
 // write_in_file( potencia(lenguajes_[1], 2));
 // write_in_file( potencia(lenguajes_[1], 5));
 // write_in_file( potencia(lenguajes_[1], 10));
 // fileOut_ << "Cierre Positivo\n";
 // write_in_file( positivo(lenguajes_[1]) );
 // fileOut_ << "Cierre de Kleen\n";
 // write_in_file( kleen(lenguajes_[1]) );
}

void calculadora_t::operate(lenguaje_t L1, lenguaje_t L2) {
  switch(op_) {
    case 1: {
      write_in_file(concatena(L1, L2));
      break;
      }
    case 2: {
      write_in_file(uniones(L1, L2));
      break;
      }
    case 3: {
      write_in_file(interseccion(L1, L2));
      break;
      }
    case 4: {
      write_in_file(diferencia(L1, L2));
      break;
      }
    case 5: {
      sublenguaje(L1, L2)? fileOut_ << "TRUE\n": fileOut_ << "FALSE\n";
      break;
      }
    case 6: {
      igual(L1, L2)? fileOut_ << "TRUE\n": fileOut_ << "FALSE\n";
      break;
      }
    case 7: {
      write_in_file(inversa(L1));
      break;
      }
    case 8: {
      write_in_file(potencia(L1,5));
      break;
      }
    case 9: {
      write_in_file(positivo(L1));
      break;
      }
    case 10: {
      write_in_file(kleen(L1));
      break;
      }
    default: std::cerr << "Fallo en el operador de entrada" << std::endl;
  }

}

bool calculadora_t::read_file() {
  std::string aux;
  std::set<std::string> lenguaje;
  std::string delimiter=",";
  size_t pos = 0;
  if (fileIn_.is_open() ) {
    while (getline (fileIn_, aux)) {
      boost::erase_all(aux," ");
      if ( aux[0] == '{' && aux[aux.size()-1] == '}')
      {
        aux = aux.substr(1, aux.size()-1);
        while ((pos = aux.find(delimiter)) != std::string::npos) {
          lenguaje.insert( aux.substr(0, pos)) ;
          aux.erase(0, pos + delimiter.length());
        }
        lenguaje.insert( aux.substr(0, aux.size()-1) );
      }
      lenguajes_.push_back(lenguaje);
      lenguaje.clear();
    }
    return true;
  }
  else return false;
}

void calculadora_t::print() {
  for (size_t i=0; i < lenguajes_.size()-1; i++) {
    std::set<std::string>::iterator it = lenguajes_[i].begin();
    std::cout << "Lenguaje "<< i+1 << " :\n";
    while ( it != lenguajes_[i].end()) {
      std::cout << " " << *it << " ";
      it++;
    }
    std::cout << std::endl;
  }

}

void calculadora_t::write_in_file( lenguaje_v Leng) {
  fileOut_ << "{ ";
  for (size_t i = 0; i < Leng.size()-1; i++) {
    i == Leng.size() ? (fileOut_ <<  Leng[i]): (fileOut_ << Leng[i] << ", ");
  }
  fileOut_ << " }\n";
}
void calculadora_t::write_in_file( lenguaje_t Leng) {
  lenguaje_t::iterator it = Leng.begin();
  fileOut_ << "{ ";
  while ( it != Leng.end() ) {
//  for (size_t i = 0; i < Leng.size()-1; i++) {
    it == --Leng.end() ? (fileOut_ <<  *it): (fileOut_ << *it << ", ");
    it++;
  }
  if (infi) fileOut_ << ", ...";
  fileOut_ << " }\n";
  infi = false;
}

lenguaje_t calculadora_t::concatena(lenguaje_t L1, lenguaje_t L2) {
  lenguaje_t aux;
  if ( *L1.begin() == "") return L2;
  if ( *L2.begin() == "") return L1;
  for(auto it_i = L1.begin(); it_i != L1.end();it_i++)
  {
    for(auto it_j = L2.begin(); it_j != L2.end();it_j++)
    {
      if(*it_i == "&") aux.insert(*it_j);
      else if (*it_j == "&") aux.insert(*it_i);
        else {
           std::string temp;
           temp.append(*it_i);
           temp.append(*it_j);
           aux.insert(temp);
        }
    }
   }
  return aux;
}


lenguaje_t calculadora_t::uniones(lenguaje_t L1, lenguaje_t L2) {
  lenguaje_t aux;
  set_union(L1.begin(), L1.end(), L2.begin(), L2.end(), inserter(aux,
        aux.begin()));
  return aux;
}


lenguaje_t calculadora_t::interseccion(lenguaje_t L1, lenguaje_t L2) {
  lenguaje_t aux;
  set_intersection(L1.begin(), L1.end(), L2.begin(), L2.end(), inserter(aux,
        aux.begin()));
  return aux;
}

lenguaje_t calculadora_t::diferencia(lenguaje_t L1, lenguaje_t L2) {
  lenguaje_t aux;
  set_difference(L1.begin(), L1.end(), L2.begin(), L2.end(), inserter(aux,
        aux.begin()));
  return aux;
}


bool calculadora_t::sublenguaje(lenguaje_t L1, lenguaje_t L2) {
  return includes(L1.begin(), L1.end(), L2.begin(), L2.end());
}

bool calculadora_t::igual(lenguaje_t L1, lenguaje_t L2) {
  return equal(L1.begin(), L1.end(), L2.begin(), L2.end());
}

lenguaje_t calculadora_t::inversa( lenguaje_t L1 ) {
  lenguaje_t aux;
  std::string temp;
  for ( auto it = L1.begin(); it != L1.end(); it++) {
    temp = *it;
    std::reverse( temp.begin(), temp.end() );
    aux.insert(temp);
  }
  return aux;
}

lenguaje_t calculadora_t::potencia(lenguaje_t L1, int n) {
  lenguaje_t aux = L1;
  if ( *L1.begin() == "&") return L1;
  else {
    switch(n) {
      case 0:
          aux.clear();
          aux.insert("&");
          return aux;
          break;
      case 1:
          return aux;
          break;
      default:
          return concatena(aux, potencia(aux , n-1 ));
    }
  }
}


lenguaje_t calculadora_t::positivo(lenguaje_t L1) {
  if ( *L1.begin() == "&") return L1;
  else {
    lenguaje_t aux, posi;
    for (int i = 1; i <= 10; i++) {
      posi = uniones( posi, potencia(L1, i));
    }
    infi = true;
    return posi;
  }
}

lenguaje_t calculadora_t::kleen(lenguaje_t L1) {
  if ( *L1.begin() == "&" ) return L1;
  else {
    lenguaje_t aux, posi;
    for (int i = 0; i <= 10; i++) {
      posi = uniones( posi, potencia(L1, i));
    }
    infi = true;
    return posi;
  }
}

















