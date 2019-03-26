#include "grafo.h"
#include <stdlib.h>
#include <stdio.h>

// Fazer a função ePonte()

int main(void){
	Grafo *G;
	int erro, direcionado = 0, valor;
	printf("Quantos vértices?\n");
	int numVertices;
	scanf("%d", &numVertices);
	

	G = criar_grafo(&numVertices, &erro, &direcionado);

	//Inicializa o grafo
	for(int x=0; x<numVertices; x++){
		for(int y=0; y<numVertices; y++){
			//Coloca 0 em tudo
			int valor = 0;
			inserir_aresta(G, &x, &y, &valor, &erro);
		}	
	}

	printf("Seja o grafo não direcionado, quantas arestas ele tem?\n");
	int numArestas;
	scanf("%d", &numArestas);

	//Montar o grafo
	valor = 1;
	int i, j;
	for (int x=0; i<numArestas; i++) {
		scanf("%d", &i);
		scanf("%d", &j);
		inserir_aresta(G, &i, &j, &valor, &erro);
	}

	int verticeVisitado[numVertices];
	int arestaVisitada[numVertices][numVertices];
	for(int i=0; i<numVertices; i++) {
		verticeVisitado[i] = 0;
	}
	for (int i=0; i<numVertices; i++) {
		for (int j=0; j<numVertices; j++) {
			arestaVisitada[i][j] = 0;
		}
	}

	/*Para exemplos*/
	arestaVisitada[0][1] = 1;
	arestaVisitada[1][0] = 1;
	verticeVisitado[0] = 1;
	verticeVisitado[1] = 1;
	int vOrigem = 1;
	int vDestino = 3;
	/*Fim exemplos*/

	if (ePonte(G, &vOrigem, &vDestino, verticeVisitado, numVertices, arestaVisitada)) {
		printf("É ponte\n");
	} else {
		printf("Não é ponte\n");
	}

	imprimir_grafo(G);
	return 0;
}