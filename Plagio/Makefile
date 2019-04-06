all: grafo.o main.o
	gcc grafolista.o plagiotest.o -o test

grafo.o:
	gcc -c -Wall grafolista.c	

main.o:
	gcc -c -Wall plagiotest.c

run:
	./test < teste.in

clear:
	rm *.o test
