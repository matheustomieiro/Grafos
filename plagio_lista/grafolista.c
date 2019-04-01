#include <stdio.h>
#include <stdlib.h>
#include "grafolista.h"

struct _aresta {
    char *nome;
    struct _aresta *prox;
};

struct _vertice {
    char *nome;
    int num_arestas;
	struct _vertice *prox;
    Aresta *primeiro_elem;
    Aresta *ultimo_elem;
};

struct _grafo {
    Vertice *vertices;
    int numVertices;
};


/*Função criar_grafo: cria um grafo;
@argumentos: void;
@retorno: retorna, se obteve sucesso, um ponteiro para o grafo criado;	
*/
Grafo *criar_grafo(){
	Grafo *G = (Grafo *)malloc(sizeof(Grafo));
	if(G == NULL){
		return NULL;
	}
	G->numVertices = 0;
	G->vertices = NULL;
	return G;
}

/*Função inserir_vertice: insere uma nova palavra na lista de vertices;
@argumentos: ponteiro para grafo G e string da palavra;
@retorno: void;	
*/
void inserir_vertice(Grafo *G, char *nome){
    Vertice *V = (Vertice *) malloc(sizeof(Vertice));
    V->nome = (char*) malloc(20*sizeof(char));
    V->nome = nome;
    V->primeiro_elem = NULL;
    V->ultimo_elem = NULL;
    V->num_arestas = 0;
    V->prox = G->vertices->prox;
    G->vertices = V;
}

/*Função buscar_vert: verifica se a palavra ja esta na lista de vertices;
@argumentos: ponteiro para grafo G e string da palavra;
@retorno: retorna, se obteve sucesso, um ponteiro para o vertice;	
*/
Vertice *buscar_vert(Grafo *G, char *word) {
	if(G != NULL){
        Vertice *V = G->vertices;
		while(V != NULL){
            if(V->nome == word) return (V);
            V = V->prox;
        }
	}
    return NULL;	
}

/*Função inserir_aresta: insere uma palavra na lista de arestas de um vertice;
@argumentos: ponteiro para grafo G, string da palavra vertice e string da palavra aresta;
@retorno: retorna void;	
*/
void inserir_aresta(Grafo *G, char *nome_vertice, char *nome_aresta){
    Vertice *V = buscar_vert(G, nome_vertice);
    if(V != NULL){
        Aresta *A = (Aresta*) malloc(sizeof(Aresta));
        A->nome = (char*) malloc(20*sizeof(char));
        A->nome = nome_aresta;
        V->num_arestas++;
        if(V->primeiro_elem != NULL){
            A->prox = V->ultimo_elem->prox;
            V->ultimo_elem = A;
        }
        else {
            V->primeiro_elem = A;
            V->ultimo_elem = A;
            A->prox = NULL;
        }
    }
    return;
}

/*Função imprime_grafo: imprime o grafo na tela;
@argumentos: ponteiro para grafo G;
@retorno: retorna void;	
*/
void imprime_grafo(Grafo *G) {
    if(G != NULL){
        Vertice *V = G->vertices;
        Aresta *A = V->primeiro_elem;
        printf("Grafo texto - %d vertices:\n", G->numVertices);
        while (V != NULL){
            printf("Vertice: %s - %d arestas\n", V->nome, V->num_arestas);
            while (A != NULL){
                printf("    -%s\n", A->nome);
                A = A->prox;
            }
        }
    }
    printf("FIM\n");
}

