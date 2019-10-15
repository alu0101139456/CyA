#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

class estado_t
{
    private:
        unsigned int val_;
        bool acept_;
        int num_trans_;
        vector<char> simbolo_;
        vector<unsigned int> destino_;
    public:
        estado_t(void);
        ~estado_t(void);
        unsigned int get_val (void);
        void set_val (unsigned int val);
        istream& set_val (istream& is);
        bool get_acept (void);
        void set_acept (bool acept);
        istream& set_acept (istream& is);
        int get_num_trans (void);
        void set_num_trans (int num_trans);
        istream& set_num_trans (istream& is);
        char get_simbolo (int pos);
        vector<char> get_simbolo(void);
        void set_simbolo (char simbolo, int pos);
        // istream& set_simbolo (istream& is);
        unsigned int get_destino (int pos);
        vector<unsigned int> get_destino(void);
        void set_destino (unsigned int destino, int pos);
        // istream& set_destino (istream& is);
        void resize_vectors (int tam);
        // unsigned int get_next(char simb);
};
