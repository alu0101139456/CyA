#include "racional_t.hpp"





void racional_t::print(void)
{
    std::cout << num_ << "/" << den_ <<  "";
}

int racional_t::get_num(void){
  return num_;
}

int racional_t::get_den(void){
  return den_;
}

double racional_t::get_f(void){
  return (num_ / den_);
}

void racional_t::set_num( int num){
  num_ = num;
}

void racional_t::set_den( int den){
  den_ = den;
}

racional_t racional_t::suma(racional_t &aux){
 if (get_den() == aux.get_den()){
    return racional_t(get_num() + aux.get_num(), get_den() );
 }
 else{
    return (racional_t(get_num() * aux.get_den() + aux.get_num() * get_den(), 
                      get_den() * aux.get_den()) ); }
}

racional_t racional_t::resta(racional_t &aux){
 if (get_den() == aux.get_den()){
    return racional_t(get_num() - aux.get_num(), get_den() );
 }
 else{
    return (racional_t(get_num() * aux.get_den() - aux.get_num() * get_den(), 
                      get_den() * aux.get_den()) );
 }
}

racional_t racional_t::mult(racional_t &aux){
  return (racional_t(get_num() * aux.get_num() ,get_den() * aux.get_den()) );
 }

racional_t racional_t::div(racional_t &aux){
  return (racional_t(get_num() * aux.get_den() ,get_den() * aux.get_num()) );
}




bool operator>( racional_t &a, racional_t &b ){
  if(a.get_f() - b.get_f() > eps){
    return true;
  }
  else return false;
}
bool operator<( racional_t &a, racional_t &b ){
  if (a.get_f() - b.get_f() < eps){
    return true;
  }
  else return false;
}
bool operator==( racional_t &a, racional_t &b){
  if(fabs(a.get_f() - b.get_f()) < eps)
    return true;
}
racional_t operator+( racional_t &a, racional_t &b){
 if (a.get_den() == b.get_den()){
    return racional_t(a.get_num() + b.get_num(), a.get_den() );
 }
 else{
    return (racional_t(a.get_num() * b.get_den() + b.get_num() * a.get_den(), 
                      a.get_den() * b.get_den()) ); }
 
}

racional_t operator-( racional_t &a, racional_t &b){
  if (a.get_den() == b.get_den()){
    return racional_t(a.get_num() - b.get_num(), a.get_den() );
 }
 else{
    return (racional_t(a.get_num() * b.get_den() - b.get_num() * a.get_den(), 
                      a.get_den() * b.get_den()) ); }
}





