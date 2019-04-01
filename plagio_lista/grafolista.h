#ifndef GRAFOLISTA_H
#define GRAFOLISTA_H

typedef struct _aresta Aresta;
typedef struct _vertice Vertice;
typedef struct _grafo Grafo;

Grafo *criar_grafo();
void inserir_vertice(Grafo *G, char nome[]);
Vertice *buscar_vert(Grafo *G, char word[]);
void inserir_aresta(Grafo *G, char nome_vertice[], char nome_aresta[]);
void imprime_grafo(Grafo *G);

#endif