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
		 $(BIN)/automate.o \
		 $(BIN)/expr.o \

all: $(EXE)

clean:
	rm -rf $(BIN)/* $(EXE)

$(EXE): $(OFILES)
	$(CC) $(CFLAGS) -o $(EXE) $(OFILES)

$(BIN)/main.o: automate.h main.cpp 
	$(CC) $(CFLAGS) -o $(BIN)/main.o -c main.cpp

$(BIN)/lexer.o: symbole.h symbole.cpp expr.h
	$(CC) $(CFLAGS) -o $(BIN)/lexer.o -c lexer.cpp

$(BIN)/symbole.o: symbole.h symbole.cpp
	$(CC) $(CFLAGS) -o $(BIN)/symbole.o -c symbole.cpp

$(BIN)/automate.o: automate.h automate.cpp symbole.h lexer.h expr.h
	$(CC) $(CFLAGS) -o $(BIN)/automate.o -c automate.cpp

$(BIN)/expr.o: expr.cpp symbole.h expr.h
	$(CC) $(CFLAGS) -o $(BIN)/expr.o -c expr.cpp