/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * Autor: Ángel Julián Bolaño Campos                                          *
 * Asignatura: Computabilidad y Algoritmia                                    *
 * Curso: 2º Ingeniería Informática                                           *
 * Editor: VIM                                                                *
 * Estilo Google C++ Style Guide                                              *
 * Práctica 2: Análisis de Texto                                              *
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/ 

#include "../include/AnalizerWords_t.hpp"



//The constructor loads all the characters that you want to classify in set
AnalizerWords_t::AnalizerWords_t(std::string in, std::string out="fileOut.txt")
{
  try {
    fileIn_ = std::ifstream(in);
    fileOut_ = std::ofstream(out);

    get_specials_words();
    get_operators();
    get_sign();

    analize();

  }catch( std::exception& e) {
        std::cout << " Failed to charge keywords " << e.what() << "'\n";
    }
}

void AnalizerWords_t::analize() {
  char wordRead[64];
  if (fileIn_.is_open()) {
    do {
      fileIn_ >> wordRead;
      write_in_file(wordRead);
  }
  while (!fileIn_.eof());
    fileIn_.close();
  }
}

//This function collects the values of file to insert into the set
void AnalizerWords_t::get_specials_words() {
  char aux[64];
  std::ifstream spWordsFile(".specialwords.txt");
  SetStrng::iterator it;
  while ( !spWordsFile.eof() ) {
    spWordsFile >> aux;
    spWords_.insert(aux);
  }
  spWordsFile.close();

}

//This function collects the values of file to insert into the set
void AnalizerWords_t::get_operators() {
  char aux[64];
  std::ifstream spOperFile(".operators.txt");
  while ( !spOperFile.eof() ) {
    spOperFile >> aux;
    spOperators_.insert(aux);
  }
  spOperFile.close();
}

//This function collects the values of file to insert into the set
void AnalizerWords_t::get_sign() {
  char aux[64];
  std::ifstream spSignFile(".signs.txt");
  while ( !spSignFile.eof() ) {
    spSignFile >> aux;
    spSign_.insert(aux);
  }
  spSignFile.close();
}

//Each word read is compared to previously stored sets. If the "find" function
//did not find the word, go to the next conditional.
//Returned values will be classified by the "void write_in_File"
int AnalizerWords_t::get_type(std::string stringToA) {
  SetStrng::iterator it;

  it = spWords_.find(formattingL(stringToA));
  if (it != spWords_.end())
    return 0;

  it = spOperators_.find(stringToA);
  if (it != spOperators_.end())
    return 1;

  it = spSign_.find(stringToA);
  if (it != spSign_.end())
    return 2;

  if (is_int(stringToA))
    return 3;
  if (is_float(stringToA))
    return 4;

  if (is_no_word(stringToA))
    return 5;
  else
    return 6;
}

//The values returned by the get_Type function will be interpreted by switch 
//to print in the output file
void AnalizerWords_t::write_in_file(char wordToA[64]) {
  std::string finalValue = wordToA;
  int option = get_type(finalValue);
  switch(option) {
    case 0:  {
      fileOut_ << formattingU(finalValue) << "\n";
      break;
      }
    case 1:  {
      fileOut_ << "OP " << finalValue << "\n";
      break;
      }
    case 2:  {
      fileOut_ << "SIG " << finalValue << "\n";
      break;
      }
    case 3:  {
      fileOut_ << "INT " << finalValue << "\n";
      break;
      }
    case 4:  {
      fileOut_ << "FLOAT " << finalValue << "\n";
      break;
      }
    case 5:  {
      fileOut_ << "PAL " << finalValue << "\n";
      break;
      }
    default:  {
      fileOut_ << "DESCONOCIDA " << finalValue << "\n";
      break;
      }


  }
}

//Returns true only if the string has numeric characters
bool AnalizerWords_t::is_int(std::string verify) {
    return verify.find_first_not_of("0123456789") == std::string::npos;
}

//Returns true only if the string has numeric characters and dot
bool AnalizerWords_t::is_float(std::string verify_float) {
    return verify_float.find_first_not_of(".0123456789") == std::string::npos;
}


//Use the ASCII value to print string with DIFFERENT classification
bool AnalizerWords_t::is_no_word(std::string verify_word) {
  if ( (verify_word[0]  >= 65  && verify_word[0] < 91) |
      (verify_word[0] > 96 && verify_word[0] <= 192) )
    return true;
  else
    return false;
}

//Put all word lower
std::string AnalizerWords_t::formattingL(std::string &aux) {
  std::for_each(aux.begin(), aux.end(), [](char &c) { c =::tolower(c);});
  return aux;
}
//Put all word upper
std::string AnalizerWords_t::formattingU(std::string &aux) {
  std::for_each(aux.begin(), aux.end(), [](char &c) { c =::toupper(c);});
  return aux;
}




