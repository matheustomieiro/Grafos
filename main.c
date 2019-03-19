#include "grafo.h"
#include <stdlib.h>
#include <stdio.h>

int main(void){
	Grafo *G;
	int n=5, erro, direcionado = 0, valor;
	G = criar_grafo(&n, &erro, &direcionado);
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			//Coloca 0 em tudo
			int valor = 0;
			inserir_aresta(G, &i, &j, &valor, &erro);
		}	
	}

	//Montar o grafo
	valor = 1;
	int i, j;
	i=0;j=1;
	inserir_aresta(G, &i, &j, &valor, &erro);
	i=1;j=2;
	inserir_aresta(G, &i, &j, &valor, &erro);
	i=1;j=3;
	inserir_aresta(G, &i, &j, &valor, &erro);
	i=1;j=4;
	inserir_aresta(G, &i, &j, &valor, &erro);
	i=2;j=3;
	inserir_aresta(G, &i, &j, &valor, &erro);
	i=0;j=4;
	inserir_aresta(G, &i, &j, &valor, &erro);

	int vertice = 4;
	DFS(G, &vertice);
	if (visitouTodos(G)) {
		printf("Visitou todos, ou seja, não é ponte\n");
	} else {
		printf("Nao visitou todos, ou seja, é ponte\n");
	}

	imprimir_grafo(G);
	return 0;
}