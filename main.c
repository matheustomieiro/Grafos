#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"

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
	for (int x=0; x<numArestas; x++) {
		scanf("%d", &i);
		scanf("%d", &j);
		inserir_aresta(G, &i, &j, &valor, &erro);
	}

	if(!(ciclo_euleriano(G))) {
		printf("Este grafo não pode ter um ciclo euleriano\n");
		return 0;
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

	int caminho[MAX_QTD_CAMINHO];
	int qtdCaminho=0;

	//Começando do vertice 0
	int vOrigem = 0;
	caminho[qtdCaminho] = 0;
	qtdCaminho++;
	int vDestino;
// 	//Verificar vertices conectados
// 	for (vDestino=0; vDestino<numVertices; vDestino++) {
// //Se não forem os mesmo vértices e     há aresta               e   ela não foi visitada                  e       não é ponte
// 		if(vOrigem != vDestino && G->m[vOrigem][vDestino] == 1 && arestaVisitada[vOrigem][vDestino] != 1 && !(ePonte(G, &vOrigem, &vDestino, verticeVisitado, numVertices, arestaVisitada)) && ) {
// 			arestaVisitada[vOrigem][vDestino] = 1;
// 			arestaVisitada[vDestino][vOrigem] = 1;
// 			verticeVisitado[vDestino] = 1;
// 			caminho[qtdCaminho] = vDestino;
// 			qtdCaminho++;
// 			vOrigem = vDestino;
// 			vDestino = 0;
// 		}
// 	}


	printf("Qual o vértice de inicio?\n");
	int vInicio;
	scanf("%d", &vInicio);

	vDestino = vInicio;

	while(!(visitouTodos(G, verticeVisitado)) && vDestino<=numVertices){
//Se não forem os mesmo vértices e     há aresta               e   ela não foi visitada                  e       não é ponte
		// printf("arestaVisitada[%d][%d] = %d\n", vOrigem, vDestino, arestaVisitada[vOrigem][vDestino]);
		if(vOrigem != vDestino && G->m[vOrigem][vDestino] == 1 && arestaVisitada[vOrigem][vDestino] != 1 && !(ePonte(G, &vOrigem, &vDestino, verticeVisitado, numVertices, arestaVisitada))) {
			// printf("=============vDestino: %d\n", vDestino);
			arestaVisitada[vOrigem][vDestino] = 1;
			arestaVisitada[vDestino][vOrigem] = 1;
			verticeVisitado[vDestino] = 1;
			caminho[qtdCaminho] = vDestino;
			qtdCaminho++;
			vOrigem = vDestino;
			vDestino = 0;
		} else {
			vDestino++;
		}
		// printf("visitou todos = %d\n", visitouTodos(G, verticeVisitado));
	}

	caminho[qtdCaminho] = 0;

	for(int k=0; k<qtdCaminho+1; k++) {
		printf("%d\n", caminho[k]);
	}

	// /*Para exemplos*/
	// arestaVisitada[0][1] = 1;
	// arestaVisitada[1][0] = 1;
	// verticeVisitado[0] = 1;
	// verticeVisitado[1] = 1;
	// int vOrigem = 0;
	// int vDestino = 3;
	// /*Fim exemplos*/

	// if (ePonte(G, &vOrigem, &vDestino, verticeVisitado, numVertices, arestaVisitada)) {
	// 	printf("É ponte\n");
	// } else {
	// 	printf("Não é ponte\n");
	// }

	// imprimir_grafo(G);
	return 0;
}