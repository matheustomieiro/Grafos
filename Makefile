all: grafo.o main.o
	gcc grafo.o main.o -o main

grafo.o:
	gcc -c -Wall grafo.c	

main.o:
	gcc -c -Wall main.c

run:
	./main

clear:
	rm *.o main
