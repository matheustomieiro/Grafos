#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"


struct grafo{
	elem m[MAX_NUM_VERTICES][MAX_NUM_VERTICES];	
	int numVertices;
	int direcionado;
};
/*Função criar_grafo: cria um grafo;
@argumentos: ponteiros para inteiros n, erro e direcionado;
@retorno: retorna, se obteve sucesso, um ponteiro para o grafo criado;	
*/
Grafo *criar_grafo(int *n, int *erro, int *direcionado){
	Grafo *G = (Grafo *)malloc(sizeof(Grafo));
	if(!G){
		*erro = 1;
		return NULL;
	}
	*erro = 0;
	int N = *n;
	if(N > MAX_NUM_VERTICES){
		*n = MAX_NUM_VERTICES;
		*erro = 1;
	}
	if(N < 0){
		*n = 0;
		*erro = 1;
	}
	G->numVertices = N;
	for(int i=0; i<MAX_NUM_VERTICES; i++)
		for(int j=0; j<MAX_NUM_VERTICES; j++)
			G->m[i][j] = SEM_ARESTA;
	G->direcionado = *direcionado;
	return G;
}

/*Função apagar_grafo: apaga um grafo;
@argumentos: ponteiros para o grafo e ponteiro para o inteiro erro;
*/
void apagar_grafo(Grafo *G, int *erro){
	if(G != NULL) free(G);
	*erro = 0;
}


/*Função inserir_aresta: cria um grafo;
@argumentos: ponteiros para inteiros n e erro;
@retorno: retorna, se obteve sucesso, um ponteiro para o grafo criado;	
*/
void inserir_aresta(Grafo *G, int *v1, int *v2, elem *n, int *erro){
	if(G == NULL || *v1 > (G->numVertices-1) || *v2 > (G->numVertices-1)) *erro = 1;
	else{
		
		G->m[*v1][*v2] = *n;
		if(!(G->direcionado)) G->m[*v2][*v1] = *n;
		*erro = 0;
	}	
}

elem retirar_aresta(Grafo *G, int *v1, int *v2, int *erro){
	elem ret = SEM_ARESTA;
	if(G == NULL || *v1 > (G->numVertices-1) || *v2 > (G->numVertices-1)) *erro = 1;
	else{
		ret = G->m[*v1][*v2];
		if(ret == SEM_ARESTA) *erro = 1;
		else{
			G->m[*v1][*v2] = SEM_ARESTA;
			if(!(G->direcionado)) G->m[*v2][*v1] = SEM_ARESTA;
			*erro = 0;
		}	
	}
	return ret;	
}

/*
verifica se dois vértices(v1->v2 se direcionado) são adjacentes
*/
int verificar_aresta(Grafo *G, int *v1, int *v2, int *erro){
	if(*v1 < 0 || *v2 < 0 || *v1 >= G->numVertices || *v2 >= G->numVertices){
		*erro = 1;
		return -1;
	}	
	if(G->m[*v1][*v2] != SEM_ARESTA) return 1;
	return 0;
}
/*
Imprime a matriz de adjacência;(mudar máscara quando mudar o elem)
*/
void imprimir_grafo(Grafo *G){
	for(int i=0; i<G->numVertices; i++){
		for(int j=0; j<G->numVertices; j++){
			printf("%d\t", G->m[i][j]);
		}
		printf("\n");
	}
}

/*
Cria um grafo transposto;
*/
Grafo *grafo_transposto(Grafo *G, int *erro){
	int e;
	Grafo *aux = NULL;
	if(G != NULL && G->direcionado == 1){
		*erro = 0;
		aux = criar_grafo(&(G->numVertices), &e, &(G->direcionado));
		for(int i=0; i<G->numVertices; i++){
			for(int j=0; j<G->numVertices; j++){
				if(G->m[i][j] != SEM_ARESTA) aux->m[j][i] = G->m[i][j];
			}
		}
	}else *erro = 1;		
	return aux;
}
/*
@argumentos: ponteiros para o grafo, um vértice e erro;
@retorno: retorna 1 se a lista adjacente do vertice for vazia e 0, caso contrário;
*/
int lista_adj_vazia(Grafo *G, int *v, int *erro){
	if(*v >= G->numVertices || *v < 0){
		*erro = 1;
		return 1;
	}else{
		*erro = 0;
		int aux = 0, lista_vazia = 1;
		while((aux < G-> numVertices) && (lista_vazia)){
			if(G->m[*v][aux] != SEM_ARESTA)
				lista_vazia = 0;
			else aux++;
		}
		return (lista_vazia);
	}
}

/*
@argumentos: ponteiros para o grafo, um vértice e erro;
@retorno: retorna o primeiro vértice adjacente ou -1 se não haver lista adjacente;
*/
int primeiro_lista_adj(Grafo *G, int *v, int *erro){
	if(*v >= G->numVertices || *v < 0) *erro = 1;
	else{
		*erro = 0;
		int aux = 0;
		if(!lista_adj_vazia(G, v, erro)){
			while(aux < G->numVertices){
				if(G->m[*v][aux] != SEM_ARESTA)	return aux;
				else aux++;
			}
		}		
	}
	return -1;
}

/*
Procura o próximo vértice adjacente;
*/
void prox_adj(Grafo *G, int *v, int *adj, elem *p, int *prox, int *fim_lista_adj, int *erro){
	if(*v > G->numVertices || *v < 0)	*erro = 1;
	else{
		*erro = 0;
		*adj = *prox;
		*p = G->m[*v][*prox];
		(*prox)++;
		while((*prox < G->numVertices) && (G->m[*v][*prox] == SEM_ARESTA)) (*prox)++;
		if(*prox >= G->numVertices) *fim_lista_adj = 1;
	}
}
/*
Grafo *gerar_transposto(Grafo *G, int *erro){
	int v, adj, p, aux, fim_lista_adj;
	Grafo 

}*/

/*considero direcionado*/
elem aresta_menor_peso(Grafo *G, int *erro){
	//int *vet = ();
	elem menor=-1;
	int aux=0; 
	if(G != NULL){
		for(int i=0; i<G->numVertices; i++){
			for(int j=0; j<G->numVertices; j++){
				if(G->m[i][j] != SEM_ARESTA){
					if(aux == 0){
						menor = G->m[i][j];
						aux++;
					}
					if(G->m[i][j] < menor) menor = G->m[i][j];
				}	
			}
		}
		return menor;
	}
	return -1;
}

int grau_vertice(Grafo *G, int *v){
	int aux=0;
	for(int i=0; i<G->numVertices; i++){
		if(*v != i && G->m[*v][i] != SEM_ARESTA) aux++;
	}
	return aux;
}

/*Algoritmo de Fleury*/
/*Considerando um grafo não direcionado*/
/*Retorna uma string com um ciclo euleriano ou com um char '#' se não há ciclo*/
int ciclo_euleriano(Grafo *G){
	int grau;
	/*Checa se algum dos vértices do grafo tem grau ímpar ou é desconexo*/
	for(int i=0; i<G->numVertices; i++){
		grau = grau_vertice(G, i);
		/*Verificando condicoes suficientes para que existe um ciclo euleriano*/
		if(grau == 0 || grau % 2 == 1){
			return 0;
		}
	}
	return 1;
}

// Faz uma busca em profundidade a partir de um vertice, e marca os caminhos visitados em uma matriz
void DFS(Grafo *G, int *vertice, int *verticeVisitado, int numVertices, int arestaVisitada[][numVertices]) {
	verticeVisitado[*vertice] = 1;
	for(int prox=0; prox<G->numVertices; prox++){
		//Se há uma aresta e não foi visitado
		if(G->m[*vertice][prox]==1 && !(arestaVisitada[*vertice][prox])) {
			arestaVisitada[*vertice][prox] = 1;
			arestaVisitada[prox][*vertice] = 1;
			printf("Visitando %d %d\n", *vertice, prox);
			DFS(G, &prox, verticeVisitado, numVertices, arestaVisitada);
			printf("Saindo da rescursao e estou no vertice %d\n", *vertice);
		}
	}
}

int visitouTodos(Grafo *G, int *verticeVisitado) {
	for (int i=0; i<G->numVertices; i++) {
		if(verticeVisitado[i] == 0) {
			return 0;
		}
	}
	return 1;
}

/*Verifica se uma aresta é ponte (se ao ser apagada é impossibilitada a conexão com os demais vértices)*/
int ePonte(Grafo *G, int *vOrigem, int *vDestino, int verticeVisitado[], int numVertices, int arestaVisitada[][numVertices]) {
	//Copiar os marcadores de caminho para não alterar o caminho percorrido na main
	int copiaVerticeVisitado[numVertices];
	int copiaArestaVisitada[numVertices][numVertices];
	for(int i=0; i<numVertices; i++) {
		copiaVerticeVisitado[i] = verticeVisitado[i];
	}
	for (int i=0; i<numVertices; i++) {
		for (int j=0; j<numVertices; j++) {
			copiaArestaVisitada[i][j] = arestaVisitada[i][j];
		}
	}
	copiaArestaVisitada[*vOrigem][*vDestino] = 1;
	copiaArestaVisitada[*vDestino][*vOrigem] = 1;

	//Faz uma busca em profundidade para verificar se a conexão com os outros vértices é possível
	DFS(G, vDestino, copiaVerticeVisitado, numVertices, copiaArestaVisitada);
	if (visitouTodos(G, copiaVerticeVisitado)) {
		return 0;
	} else {
		return 1;
	}
}