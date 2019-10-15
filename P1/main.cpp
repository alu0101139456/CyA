#include <iostream>
#include "racional_t.hpp"
#include <vector>
#include <unistd.h>
#include "read_t.hpp"
void help(void);

void writeInFile( racional_t aux, std::ofstream &os);

int menu(void)
{
    int option;
    std::cout << "     MENU" << "\n";
    std::cout << "1.- Introducir fracciones por teclado" << "\n";
    std::cout << "2.- Introducir fracciones por fichero" << "\n";
    std::cout << "3.- Imprimir por pantalla fracciones almacenadas" << "\n";
    std::cout << "4.- Imprimir en fichero fracciones almacenadas" << "\n";

    std::cout << "\nIntroduzca opción: ";
    std::cin >> option;
    return option;
}

racional_t c_to_ra(char a[8])
{
  racional_t aux;   
  aux.set_num(a[0] - 48 );
  aux.set_den(a[2] - 48 );
  return aux;
}

int main(int argc, char *argv[])
{
    read_t leo;
    std::vector<racional_t> lista;
    lista.resize(10);
    std::ofstream output(argv[3]);
    racional_t aux;
    racional_t a,b;
    bool modo = false;
    int c;
    std::string fileOutput;
    //char outputFile;
    system("clear");
    if (argc == 1){ 
      help();
      exit(1);
    }
    while ( (c = getopt(argc, argv, ":ihf:s:r:m:d" ) ) != -1)
    {
        switch(c)
        {
            case 'h':
                help();
                break;

            case 'i':
                std::cout << "Modo Interactivo" << std::endl;
                modo=true;
                break;
            case 'f':
                
                lista = leo.file_name(argv[2]);
                fileOutput = argv[3];
                
                for (int i = 0; i<3; i++)
                {
                  lista[i].print();
                  std::cout << " + "; 
                  lista[i+1].print();
                  std::cout << " = ";
                  aux = lista[i].suma(lista[1+i]);
                  aux.print();
                  std::cout << " \n";
                } 
                break;

            case 's':
                a = c_to_ra(argv[2]);
                b = c_to_ra(argv[3]);
                aux = a.suma(b);
                aux.print();
                std::cout << "\n";
                break;

            case 'r':
                a = c_to_ra(argv[2]);
                b = c_to_ra(argv[3]);
                aux = a.resta(b);
                aux.print();
                std::cout << "\n";
                break;

            case 'm':
                a = c_to_ra(argv[2]);
                b = c_to_ra(argv[3]);
                aux = a.mult(b);
                aux.print();
                std::cout << "\n";
                break;
           
            case 'd':
                a = c_to_ra(argv[2]);
                b = c_to_ra(argv[3]);
                aux = a.div(b);
                aux.print();
                std::cout << "\n";
                break;

           default:
                help() ;
                break;

        }


    }

    if( modo)
    {
        int op=-1;
        while (op != 0)
        {
                
            read_t A;
            op = menu();
            switch(op)
            {
                case 1:
                    std::cout << "Introduccion de valores por teclado" << std::endl;
                    break;
                case 2:
                    std::cout << "Valores por fichero" << std::endl;
                    A.get_name();
                    break;
                case 3:
                    A.print_file();
                    break;
                    
            }
        }

    }
}


void help (void)
{
    std::cout << "HELP                      User Commands" << "\n";
    std::cout << "NAME" << std::endl;
    std::cout << "racionales  - Manejo de numeros racionales" << std::endl;
    std::cout << "SYNOPSIS" << std::endl;
    std::cout << "racionales [OPTION]... [FILE]..." << std::endl;
    std::cout << "racionales [OPTION] [RATIONAL] [RATIONAL]" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "-h   HELP" << std::endl;
    std::cout << "-i   MODO INTERACTIVO - VISUALIZA POR PANTALLA UN MENU" << std::endl;
    std::cout << "-s   SUMA - MUESTRA POR PANTALLA LA SUMA DE DOS RACIONALES INTRODUCIDOS POR LINEA DE COMANDO" << std::endl;
    std::cout << "-r   RESTA - MUESTRA POR PANTALLA LA RESTA DE DOS RACIONALES INTRODUCIDOS POR LINA DE COMANDO" << std::endl;
    std::cout << "-m   MULTIPLICACION - MUESTRA POR PANTALLA LA MULTIPLICACION DE DOS NUMEROS RACIONALES INTRODUCIDOS POR LINEA DE COMANDO" << std::endl;
    std::cout << "-d   DIVISION - MUESTRA POR PANTALLA LA DIVISION DE DOS NUMEROS RACIONALES INTRODUCIDOS POR LINEA DE COMANDO" << std::endl;

    
}
  

void writeInFile( std::vector<racional_t> &rac ,std::ofstream &os)
{
  racional_t aux;
  if( os.is_open())
  {
     for (int i=0; i<4; i++)
     {
        rac[i].print();
        os << " + "; 
        rac[i+1].print();
        os << " = ";
        aux = rac[i].suma(rac[1+i]);
        aux.print();
     }

  }
}
