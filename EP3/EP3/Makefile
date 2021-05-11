CFLAGS=-O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wno-unused-but-set-variable -Wshadow
LIBS=-lm
EXECUTAVEL=EP3

all: $(EXECUTAVEL)

$(EXECUTAVEL): main.o Util.o arvoreAVL.o arvore-bin.o
	gcc main.o Util.o arvoreAVL.o arvore-bin.o $(LIBS) -o $(EXECUTAVEL)

main.o: main.c
	gcc $(CFLAGS) -c main.c

Util.o: Util.c
	gcc $(CFLAGS) -c Util.c

arvoreAVL.o: arvoreAVL.c
	gcc $(CFLAGS) -c arvoreAVL.c

arvore-bin.o: arvore-bin.c
	gcc $(CFLAGS) -c arvore-bin.c

clean: 
	rm -rf *.o $(EXECUTAVEL)

memcheck: $(EXECUTAVEL)
	valgrind --tool=memcheck --leak-check=full ./$(EXECUTAVEL) -d Dicionario.txt -t TextoExemplo.txt
	
run: $(EXECUTAVEL) 
	./$(EXECUTAVEL) -d Dicionario.txt -t TextoExemplo.txt