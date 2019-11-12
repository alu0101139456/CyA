CC=g++
CXXFLAGS=-std=c++17 -ggdb

OBJS = main.o symbol_t.o cadena_t.o cfg_t.o CFG2NFA_t.o estado_t.o nfa_t.o

all: ${OBJS}
					$(CC) $(CXXFLAGS) -o main ${OBJS}
clean:
				rm -rf *.o main
