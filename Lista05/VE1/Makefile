CFLAGS=-O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow
LIBS=-lm
EXECUTAVEL=VE1

all: $(EXECUTAVEL)

$(EXECUTAVEL): main.o VE1.o
	gcc main.o VE1.o $(LIBS) -o $(EXECUTAVEL)

main.o: main.c
	gcc $(CFLAGS) -c main.c

VE1.o: VE1.c
	gcc $(CFLAGS) -c VE1.c


clean: 
	rm -rf *.o $(EXECUTAVEL)


run: $(EXECUTAVEL)
	./$(EXECUTAVEL)