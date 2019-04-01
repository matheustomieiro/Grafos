all: grafo.o main.o
	gcc grafolista.o plagio.o -o test

grafo.o:
	gcc -c -Wall grafolista.c	

main.o:
	gcc -c -Wall plagio.c

run:
	./test

clear:
	rm *.o test
