CC=g++
CXXFLAGS=-std=c++17 -ggdb

OBJS = main.o NFA2DFA_t.o alfabeto_t.o caracter_t.o estado_t.o dfa_t.o nfa_t.o conjunto_estado_t.o DFA2dot.o

all: ${OBJS}
					$(CC) $(CXXFLAGS) -o main ${OBJS}
clean:
				rm -rf *.o main
