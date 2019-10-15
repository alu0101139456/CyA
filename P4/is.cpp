#include "estado.h"

estado_t::estado_t(void):
    val_(0),
        acept_(0),
    num_trans_(0),
    simbolo_(0),
    destino_(0){}

estado_t::~estado_t(void)
{
    
}

unsigned int estado_t::get_val (void)
{
    return val_;
}

void estado_t::set_val (unsigned int val)
{
    val_ = val;
}

istream& estado_t::set_val (istream& is)
{
    is >> val_;
    return is;
}

bool estado_t::get_acept (void)
{
    return acept_;
}

void estado_t::set_acept (bool acept)
{
    acept_ = acept;
}

istream& estado_t::set_acept (istream& is)
{
    is >>acept_;
    return is;
}

int estado_t::get_num_trans (void)
{
    return num_trans_;
}

void estado_t::set_num_trans (int num_trans)
{
    num_trans_ = num_trans;
}

istream& estado_t::set_num_trans (istream& is)
{
    is >>num_trans_;
    return is;
}

char estado_t::get_simbolo (int pos)
{
    return simbolo_[pos];
}

vector<char> estado_t::get_simbolo(void)
{
    return simbolo_;
}

void estado_t::set_simbolo (char simbolo, int pos)
{
    simbolo_[pos] = simbolo;
}

// istream& estado_t::set_simbolo (istream& is)
// {
//     char dummy;
//     is>> dummy;
//     simbolo_.push_back(dummy);
//     return is;
// }

unsigned int estado_t::get_destino (int pos)
{
    return destino_[pos];
}

vector<unsigned int> estado_t::get_destino(void)
{
    return destino_;
}

void estado_t::set_destino (unsigned int destino, int pos)
{
    destino_[pos] += destino;
}

// istream& estado_t::set_destino (istream& is)
// {
//     int dummy;
//     is>> dummy;
//     simbolo_.push_back(dummy);
//     return is;
// }

void estado_t::resize_vectors (int tam)
{
    simbolo_.resize(tam);
    destino_.resize(tam);
}

/*unsigned int get_next (char simb)
{
    for(int i = 0; i < num_trans_; i++)
    {
        if(simbolo_[i] == simb)
        {
            return destino_[i];
        }
    }
}*/#include "estado.h"

estado_t::estado_t(void):
    val_(0),
    acept_(0),
    num_trans_(0),
    simbolo_(0),
    destino_(0){}

estado_t::~estado_t(void)
{
    
}

unsigned int estado_t::get_val (void)
{
    return val_;
}

void estado_t::set_val (unsigned int val)
{
    val_ = val;
}

istream& estado_t::set_val (istream& is)
{
    is >> val_;
    return is;
}

bool estado_t::get_acept (void)
{
    return acept_;
}

void estado_t::set_acept (bool acept)
{
    acept_ = acept;
}

istream& estado_t::set_acept (istream& is)
{
    is >>acept_;
    return is;
}

int estado_t::get_num_trans (void)
{
    return num_trans_;
}

void estado_t::set_num_trans (int num_trans)
{
    num_trans_ = num_trans;
}

istream& estado_t::set_num_trans (istream& is)
{
    is >>num_trans_;
    return is;
}

char estado_t::get_simbolo (int pos)
{
    return simbolo_[pos];
}

vector<char> estado_t::get_simbolo(void)
{
    return simbolo_;
}

void estado_t::set_simbolo (char simbolo, int pos)
{
    simbolo_[pos] = simbolo;
}

// istream& estado_t::set_simbolo (istream& is)
// {
//     char dummy;
//     is>> dummy;
//     simbolo_.push_back(dummy);
//     return is;
// }

unsigned int estado_t::get_destino (int pos)
{
    return destino_[pos];
}

vector<unsigned int> estado_t::get_destino(void)
{
    return destino_;
}

void estado_t::set_destino (unsigned int destino, int pos)
{
    destino_[pos] += destino;
}

// istream& estado_t::set_destino (istream& is)
// {
//     int dummy;
//     is>> dummy;
//     simbolo_.push_back(dummy);
//     return is;
// }

void estado_t::resize_vectors (int tam)
{
    simbolo_.resize(tam);
    destino_.resize(tam);
}

/*unsigned int get_next (char simb)
{
    for(int i = 0; i < num_trans_; i++)
    {
        if(simbolo_[i] == simb)
        {
            return destino_[i];
        }
    }
}*/
