 /*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 2: Análisis de Texto                                              *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
//calculadora_t.hpp

#include<iostream>
#include<string>
#include<fstream>
#include <boost/algorithm/string.hpp>
#include<set>
#include<algorithm>
#include<iterator>
#include<vector>

typedef std::set<std::string> lenguaje_t;
typedef std::vector<std::string> lenguaje_v;


class calculadora_t {
 private:
  std::ifstream fileIn_;
  std::ofstream fileOut_;
  std::vector<lenguaje_t> lenguajes_;
  bool infi = false;
  int op_;

 public:
  calculadora_t () { }

  calculadora_t(std::string in, std::string out, std::string option);
  ~calculadora_t() {}

  bool read_file();
  void print();
  void write_in_file( lenguaje_v Leng);
  void write_in_file( lenguaje_t Leng);

  lenguaje_t concatena (lenguaje_t L1, lenguaje_t L2);
  lenguaje_t uniones(lenguaje_t L1, lenguaje_t L2);
  lenguaje_t interseccion(lenguaje_t L1, lenguaje_t L2);
  lenguaje_t diferencia(lenguaje_t L1, lenguaje_t L2);
  bool sublenguaje(lenguaje_t L1, lenguaje_t L2);
  bool igual(lenguaje_t L1, lenguaje_t L2);
  lenguaje_t inversa(lenguaje_t L1);
  lenguaje_t potencia(lenguaje_t L1, int n);
  lenguaje_t positivo(lenguaje_t L1);
  lenguaje_t kleen(lenguaje_t L1 );

  void operate( lenguaje_t L1, lenguaje_t L2);





};
