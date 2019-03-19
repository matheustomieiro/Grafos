#include "grafo.h"
#include <stdlib.h>
#include <stdio.h>

int main(void){
	Grafo *G;
	int n=5, erro, direcionado = 1, valor;
	G = criar_grafo(&n, &erro, &direcionado);
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			srand((i+3)*(j+7));
			valor = rand() % 40000;
			inserir_aresta(G, &i, &j, &valor, &erro);
		}	
	}
	Grafo *T = grafo_transposto(G, &erro);
	imprimir_grafo(G);
	printf("\n");
	imprimir_grafo(T);
	int i = 4;
	printf("%d\n", grau_vertice(T, &i));
	return 0;
}