#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "racional_t.hpp"
#include <bits/stdc++.h>

class read_t
{
    private:
        int id_;
        char nombre_fich_[120];
        bool control = true;
        std::string nFich_;
        std::fstream fich_;
        std::vector<racional_t> numeros_r;

    public:

        read_t(void);
        
        read_t(std::string nombre);

        ~read_t(void){};

        void get_name(void);

        std::vector<racional_t> file_name( char* name );

        bool open_file(void);

        void read_fracciones(void);

        void print_file(void);

        

};
