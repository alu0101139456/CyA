








#include<iostream>
#include "symbol_t.hpp"
#include<vector>


class cadena_t{
 private:
  std::vector<symbol_t> cadena_;
  long int id_;
  bool is_terminal_;

 public:
  cadena_t():id_(0), is_terminal_(true) {}
  ~cadena_t() {}
  cadena_t(const cadena_t& rhs);


  void append( symbol_t aux);

  const std::vector<symbol_t>& get_cadena() const;
  long int get_id() const;
  bool is_terminal() const;

  cadena_t operator=(const cadena_t& rhs);
  bool operator<(const cadena_t& rhs) const;
};




