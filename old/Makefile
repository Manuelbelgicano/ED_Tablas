#MAKEFILE PARA IR TESTEANDO LOS DISTINTOS MODULOS
#NO ES EL DEFINITIVO


BIN=./bin
OBJ=./obj
SRC=./src
INC=./include
LIB=./lib
ZIP=./zip
DOC=./doc

OPT=-Wall -g
PRJ=ED_TABLAS


all:$(BIN)/tabla


$(BIN)/tabla: $(OBJ)/main.o $(OBJ)/tabla.o $(OBJ)/auxiliares.o
	g++ -o $(BIN)/tabla $(OBJ)/main.o $(OBJ)/tabla.o $(OBJ)/auxiliares.o

$(OBJ)/tabla.o: $(SRC)/tabla.cpp $(INC)/tabla.h
	g++ $(OPT) -c $(SRC)/tabla.cpp -o $(OBJ)/tabla.o -I$(INC)

$(OBJ)/main.o: $(SRC)/main.cpp $(INC)/auxiliares.h $(INC)/tabla.h
	g++ $(OPT) -c $(SRC)/main.cpp -o $(OBJ)/main.o -I$(INC)

$(OBJ)/auxiliares.o: $(SRC)/auxiliares.cpp $(INC)/tabla.h
	g++ $(OPT) -c $(SRC)/auxiliares.cpp -o $(OBJ)/auxiliares.o -I$(INC)

clean:
	rm -rf $(DOC)/html $(DOC)/latex $(OBJ)/* bin/*

doxy:
	doxygen $(DOC)/intervalo.doxy
	firefox $(DOC)/html/index.html
