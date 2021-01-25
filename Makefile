CC = g++
CFLAGS = -Wall \
		 -Werror \
		 -ansi \
		 -pedantic \
		 -std=c++11 \
		 -g

BIN = bin
EXE = main
OFILES = $(BIN)/main.o \
	     $(BIN)/lexer.o \
		 $(BIN)/symbole.o \

all: $(EXE)

clean:
	rm -rf $(BIN)/* $(EXE)

$(EXE): $(OFILES)
	$(CC) $(CFLAGS) -o $(EXE) $(OFILES)

$(BIN)/main.o: lexer.h symbole.h main.cpp 
	$(CC) $(CFLAGS) -o $(BIN)/main.o -c main.cpp

$(BIN)/lexer.o: symbole.h symbole.cpp
	$(CC) $(CFLAGS) -o $(BIN)/lexer.o -c lexer.cpp

$(BIN)/symbole.o: symbole.h symbole.cpp
	$(CC) $(CFLAGS) -o $(BIN)/symbole.o -c symbole.cpp

$(BIN)/etat.o: etat.h etat.cpp automate.h
	$(CC) $(CFLAGS) -o $(BIN)/etat.o -c etat.cpp

$(BIN)/automate.o: automate.h automate.cpp etat.h symbole.h lexer.h
	$(CC) $(CFLAGS) -o $(BIN)/automate.o -c automate.cpp