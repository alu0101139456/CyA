/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++¶ 
 * Autor: Ángel Julián Bolaño Campos                                          * 
 * Asignatura: Computabilidad y Algoritmia                                    * include "../include/del_comment_t.hpp"
 * Curso: 2º Ingeniería Informática                                           * 
 * Editor: VIM                                                                * 
 * Estilo Google C++ Style Guide                                              * 
 * Práctica 4: Eliminador de comentarios                                      * 
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/ 
//                         del_comment_t.hpp

#include "../include/del_comment_t.hpp" ç


del_comment_t(std::ifstream fileIN, std::osfstream fileOUT):
  fileIN_(fileIN),
  fileOUT_(fileOUT){
}




void del_comment_t::definir_automata() {
  //numero de estados
  //estado de arranque
  

}

//estado 0: con / pasa a E1, con " pasa a E2  OTRA COSA E0
//estado 1: con / pasa a E3, con * pasa a E4  OTRA COSA E0
//estado 2: con " pasa a E0 OTRA COSA E2
//estado 3: con / pasa a E0, con \n pasa a E0 OTRA COSA E3
//estado 4: con * pasa a E5, OTRA COSA E4
//estado 5: con * pasa a E5, con / pasa a E0 OTRA COSA E4
