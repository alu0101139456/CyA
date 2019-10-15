
#include "read_t.hpp"

read_t::read_t(void)
{
    
}

void read_t::get_name(void)
{
    std::cout << "\nLos ficheros disponibles en la carpeta actual son: \n" << std::endl;
    system("ls *.txt");
    std::cout << "Introduzca nombre de fichero" << std::endl;
    std::cin >> nombre_fich_;
    
    open_file();
}


std::vector<racional_t> read_t::file_name(char *name)
{
  strcpy( nombre_fich_ , name );
  
  if (open_file())
  {
    return numeros_r;
  }

}

read_t::read_t(std::string nombre)
{
    strcpy(nombre_fich_ , nombre.c_str());
    open_file ();
}


bool read_t::open_file(void)
{
    std::cout << "Abriendo fichero " << nombre_fich_ << std::endl;
    fich_.open(nombre_fich_);
    //fich_.open(nFich_);

    if (fich_.is_open())
    {
        read_fracciones();
    }
    else
    {
        std::cerr << "Error al abrir fichero" << std::endl;
    }
    return true;
}

void read_t::read_fracciones(void){   
  int num_, den_;
  char cadena[3];
  while (!fich_.eof()){
    fich_ >> cadena;
    num_ = cadena[0] - 48; 
    den_ = cadena[2] - 48;
    if(den_ != 0) {
      numeros_r.push_back(racional_t(num_, den_));
     }
     else control = false;;
        
  }
  if (!control)  {
    std::cerr << "Se ha leido una fracción con denominador cero no esta permitida para operar- DESCARTADA" << std::endl;
 }
    fich_.close();
}

void read_t::print_file(void)
{
    for (int i=0; i < 4; i++)
    {
        numeros_r[i].print();

    }
}
