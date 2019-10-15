/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 2: Análisis de Texto                                              *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


#include <iostream>
#include <unordered_set>
#include <string>
#include <set>
#include <fstream>
#include <algorithm>
#include <sstream>


typedef std::set<std::string> SetStrng;


class AnalizerWords_t {
 private:
  std::ifstream fileIn_;
  std::ofstream fileOut_;
  std::string wordToA_;
  SetStrng spWords_;
  SetStrng spOperators_;
  SetStrng spSign_;

 public:
  AnalizerWords_t() {}
  AnalizerWords_t(std::string in, std::string out);
  ~AnalizerWords_t() {}
  void analize();

 private:
  void get_specials_words();
  void get_operators();
  void get_sign();

  void write_in_file( char wordToA[64] );
  int get_type( std::string stringToA );

  bool is_int(std::string verify);
  bool is_float(std::string verify_float);
  bool is_no_word(std::string verify_word);

  std::string formattingL(std::string &aux);
  std::string formattingU(std::string &aux);
};

