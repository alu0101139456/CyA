

#include <iostream>

#include <fstream>
#include "racional_t.hpp"
#include <vector>
#include <cstdlib>

int main (void)
{
    int num_, den_;
    char cadena[3];
    std::fstream f("prueba.txt");
    std::vector<racional_t> a;
    racional_t aux;
    while(!f.eof())
    {
        f >> cadena;
        std::cout << cadena << std::endl;
        num_ = cadena[0] - 48;
        den_ = cadena[2] - 48;
        aux = racional_t(num_, den_);
        a.push_back(aux);
    }
    for (int i=0; i < 4; i++) 
    {
        a[i].print();
    }
}
