/**
    *@file symbol_t.hpp
    *@version 1.0
    *@date 10/11/2019
    *@author Angel Julián Bolaño Campos
    *@title Gramáticas Regulares y Autómatas Finitos
*/


#pragma once
#include<iostream>


class symbol_t {
 private:
   char name_;
   bool is_terminal_;

 public:
   symbol_t(){};
   ~symbol_t() {};
   symbol_t(const symbol_t& rhs);
   symbol_t(char name, bool terminal): name_(name), is_terminal_(terminal){}

   bool is_terminal() { return is_terminal_; }
   char get_name() const { return name_; }
   bool operator<(const symbol_t& rhs) const;
   symbol_t& operator=(const symbol_t& rhs);

   bool operator==(const symbol_t& rhs) const;

};
