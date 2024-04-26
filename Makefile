CFLAGS=-Wall
TESTDIR=PRUEBAS

all: parser prueba

.PHONY: clean 
clean:
	rm parser.cpp parser.h parser tokens.cpp *~

parser.cpp: parser.y
	bison -Wcounterexamples -d -o $@ $^

parser.hpp: parser.cpp

tokens.cpp: tokens.l parser.hpp
	flex -o $@ $^

parser: parser.cpp main.cpp tokens.cpp
	g++ $(CFLAGS) -o $@ *.cpp 

prueba: parser $(TESTDIR)/*.in 

$(TESTDIR)/%.in: parser
	@echo "PROBANDO: ./$< < $@"
	./$< < $@
	
