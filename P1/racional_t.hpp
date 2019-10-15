#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>


const double eps = 1e-6;

class racional_t
{
  private:
    int num_;
    int den_;

  public:
  
  racional_t(void){};
  
  ~racional_t(void){};

  racional_t(int num, int den):
            num_(num),
            den_(den){};

  void print(void);
  std::ofstream print(racional_t &aux);
  
  int get_num(void);
  int get_den(void);
  double get_f(void);

  void set_num( int knum);
  void set_den( int kden);

  racional_t suma(racional_t &aux);
  racional_t resta(racional_t &aux);
  racional_t mult(racional_t &aux);
  racional_t div(racional_t &aux);



};


