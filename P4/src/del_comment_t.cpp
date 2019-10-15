/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 4: Eliminador de comentarios                                      *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
//                         del_comment_t.hpp

#include "../include/del_comment_t.hpp"

del_comment_t::del_comment_t(std::ifstream fileIN, std::ofstream fileOUT) {

}



void del_comment_t::definir_automata() {
  //numero de estados
  //ESTADO 0
  //dfa_t automata;
  std::pair<char, unsigned> trans0('/',1);
  std::pair<char, unsigned> trans1('"',2);
  std::pair<char, unsigned> trans2('o',0);

}

//estado 0: con / pasa a E1, con " pasa a E2  OTRA COSA E0
//estado 1: con / pasa a E3, con * pasa a E4  OTRA COSA E0
//estado 2: con " pasa a E0 OTRA COSA E2
//estado 3: con / pasa a E0, con \n pasa a E0 OTRA COSA E3
//estado 4: con * pasa a E5, OTRA COSA E4
//estado 5: con * pasa ao E5, con / pasa a E0 OTRA COSA E4
//



void del_comment_t::read_file() {
   int aux;
   if(fileIN_.is_open()) {
     while (!fileIN_.eof()) {
       aux = fileIN_.get();
       if ( compara(aux) ) {
         char a = aux;
         if (aux == '\n')
           std::cout << "encontre salto de linea\n";
           else std::cout << "encontre " << a << " \n";
       }
     }
   }
 }


 bool del_comment_t::compara(int aux) {
   std::set<int>::iterator it = alfa_.find_symbol(aux);
   if ( it != alfa_.end() ) return true;
       else return false;
 }
