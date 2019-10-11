COMPILER	:= g++
FLAGS := -std=c++17

BIN		:= bin
SRC		:= src
INCLUDE	:= include

EXECUTABLE	:= main



$(BIN)/$(EXECUTABLE):$(SRC)/*.cpp
	@echo Compilando
	$(COMPILER) $(FLAGS) -I $(INCLUDE) $^ -o $@

clean:
	-rm $(BIN)/*

run:
	./$(BIN)/$(EXECUTABLE)
