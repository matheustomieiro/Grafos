all: plagio.o grafo.o main.o
	gcc -o plagio.exe plagio.o grafo.o main.o

grafo.o:
	gcc -c -Wall grafo.c

main.o:
	gcc -c -Wall main.c

plagio.o:
	gcc -c -Wall plagio.c

run:
	./main

clear:
	rm *.o
