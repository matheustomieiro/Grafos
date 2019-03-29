#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"

int main(void){
	Grafo *G;
	int erro, direcionado = 0, valor;
	printf("Quantos vértices?\n");
	int numVertices;
	scanf("%d", &numVertices);
	
	G = criar_grafo(&numVertices, &erro, &direcionado);

	//Inicializa o grafo(matriz)
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
	for (int x=0; x<numArestas; x++) {
		scanf("%d", &i);
		scanf("%d", &j);
		inserir_aresta(G, &i, &j, &valor, &erro);
	}

	if(!(ciclo_euleriano(G))) {
		printf("#");
		return 0;
	}

	int verticeVisitado[numVertices];
	int arestaVisitada[numVertices][numVertices];
	//Inicializando com 0
	for(int i=0; i<numVertices; i++) {
		verticeVisitado[i] = 0;
	}
	for (int i=0; i<numVertices; i++) {
		for (int j=0; j<numVertices; j++) {
			arestaVisitada[i][j] = 0;
		}
	}

	int caminho[MAX_QTD_CAMINHO];
	int qtdCaminho=0;

	//Começando do vertice 0
	int vOrigem = 0;
	caminho[qtdCaminho] = 0;
	qtdCaminho++;
	verticeVisitado[0] = 1;
	int vDestino;
	vDestino = vOrigem;

	while(!(visitouTodos(G, verticeVisitado)) && vDestino<=numVertices){
//Se não forem os mesmo vértices e     existir aresta           e   ela não foi visitada                  e       não é ponte
		if(vOrigem != vDestino && G->m[vOrigem][vDestino] == 1 && arestaVisitada[vOrigem][vDestino] != 1 && !(ePonte(G, &vOrigem, &vDestino, verticeVisitado, numVertices, arestaVisitada))) {
			// Colocar como visitados o vertice e aresta
			arestaVisitada[vOrigem][vDestino] = 1;
			arestaVisitada[vDestino][vOrigem] = 1;
			verticeVisitado[vDestino] = 1;
			//Colocar na lista do caminho
			caminho[qtdCaminho] = vDestino;
			qtdCaminho++;
			//V2=V1
			vOrigem = vDestino;
			vDestino = 0;
		} else {
			vDestino++;
		}
	}
	//Exibir o caminho (excetuando o vertice inicial)
	for(int k=0; k<qtdCaminho; k++) {
		printf("%d ", caminho[k]);
	}
	//Exibir o vertice de inicio (fechando o ciclo)
	printf("0");
	return 0;
}