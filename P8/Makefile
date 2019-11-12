CC=g++
CXXFLAGS=-std=c++17 -ggdb

OBJS = main.o symbol_t.o cadena_t.o cfg_t.o CFG2NFA_t.o caracter_t.o alfabeto_t.o estado_t.o conjunto_estado_t.o dfa_t.o nfa_t.o

all: ${OBJS}
					$(CC) $(CXXFLAGS) -o main ${OBJS}
clean:
				rm -rf *.o main
