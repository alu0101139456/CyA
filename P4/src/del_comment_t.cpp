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

del_comment_t::del_comment_t(std::ifstream& fileIN, std::ofstream& fileOUT) {
  
  definir_automata();
  read_file(fileIN, fileOUT);
}



void del_comment_t::definir_automata() {


  //ESTADO 0
  std::map<char, unsigned> transiciones0;  //Definimos un mapa para contener
                                           //todas las transiciones
  //Insertamos todas las transiones para luego mandar todo al constructor
  transiciones0.insert(trans_t('/',1));
  transiciones0.insert(trans_t('"',2));
  std::cout << "Tamaño mapa de transiciones: " << transiciones0.size() << '\n' ;
  //transiciones0.insert(trans_t('o',0));
  automata_.insert_estado(estado_t(0, 0, transiciones0, 0));


  //ESTADO 1
  std::map<char, unsigned> transiciones1;
  transiciones1.insert(trans_t('/',3));
  transiciones1.insert(trans_t('*',4));
  //transiciones1.insert(trans_t('o',0));
  automata_.insert_estado(estado_t(1, 0, transiciones1, 0));


  //ESTADO 2
  std::map<char, unsigned> transiciones2;
  transiciones2.insert(trans_t('"',0));
  transiciones2.insert(trans_t('o',2));
  automata_.insert_estado(estado_t(2, 0, transiciones2,2));


  //ESTADO 3
  std::map<char, unsigned> transiciones3;
  transiciones3.insert(trans_t('/',0));
  transiciones3.insert(trans_t('\n',0));
  //transiciones3.insert(trans_t('o',3));
  automata_.insert_estado(estado_t(3, 0, transiciones3, 3));


  //ESTADO 4
  std::map<char, unsigned> transiciones4;
  transiciones4.insert(trans_t('*',5));
//  transiciones4.insert(trans_t('o',4));
  automata_.insert_estado(estado_t(4, 0, transiciones4, 4));


  //ESTADO 5
  std::map<char, unsigned> transiciones5;
  transiciones5.insert(trans_t('*',5));
  transiciones5.insert(trans_t('/',0));
//  transiciones5.insert(trans_t('o',4));
  automata_.insert_estado(estado_t(5, 0, transiciones5,4));



  automata_.set_arranque(0);

}


//estado 0: con / pasa a E1, con " pasa a E2  OTRA COSA E0
//estado 1: con / pasa a E3, con * pasa a E4  OTRA COSA E0
//estado 2: con " pasa a E0 OTRA COSA E2
//estado 3: con / pasa a E0, con \n pasa a E0 OTRA COSA E3
//estado 4: con * pasa a E5, OTRA COSA E4
//estado 5: con * pasa ao E5, con / pasa a E0 OTRA COSA E4
//

//std::ostream& del_comment_t::write(std::ostream& os) const {
//  os << "oss";
//  return os;
//}



void del_comment_t::read_file(std::ifstream& fileIN, std::ofstream& fileOUT) {
  char aux;
  if(fileIN.is_open()) {
    while (!fileIN.eof()) {
      aux = fileIN.get();
      if ( !automata_.analiza(aux)) {
        std::cout << aux << " ";
      }
      else {          }
    }
  }
}


//char del_comment_t::compara(char aux) {
//   std::set<char>::iterator it = alfa_.find_symbol(aux);
//   if ( it != alfa_.end() ) {
//    char a = aux;
//     return a;
//   }
//       else {
//
//         return 'o';
//       }
//
// }













