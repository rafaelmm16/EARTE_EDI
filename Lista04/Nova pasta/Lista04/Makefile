## Makefile ##

LIBS=-lm
CFLAGS = -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow

all: TADRacional

TADRacional: main.o Racional.o
	gcc main.o Racional.o $(LIBS) -o TADRacional

main.o: main.c
	gcc $(CFLAGS) -c main.c

Racional.o: Racional.c
	gcc $(CFLAGS) -c Racional.c

clean: 
	rm -rf *.o TADRacional

run: TADRacional
	./TADRacional
