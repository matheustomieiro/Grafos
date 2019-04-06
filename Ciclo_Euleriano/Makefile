all: grafo.o main.o
	gcc grafo.o main.o -o main

grafo.o:
	gcc -c grafo.c	

main.o:
	gcc -c main.c

run:
	./main

clear:
	rm *.o main