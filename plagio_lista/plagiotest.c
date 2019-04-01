#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafolista.h"
#define MAX 2


int main(int argc, char const *argv[]) {
    system ("python plagio.py"); // System call to run py script
    char word_a[255], word_b[255];
    //char filename[255];
    //int n = 2; // Two files that will be compared
    Grafo *textos_a, *textos_b;// Declare an array os the struct Grafo
    FILE *txt;    
    txt = fopen("TEXT_0","r"); // Opening file in reading mode
    textos_a = criar_grafo();//Alloc space
    fscanf(txt,"%s",word_a);
    inserir_vertice(textos_a, word_a);//Insert the first vertice/word of the Graph
    memcpy(word_b, word_a, strlen(word_a));//copy the word to another variable
    while(fscanf(txt,"%s",word_a) != EOF){ //Reading all word_as in file
        if(buscar_vert(textos_a, word_a) == NULL){//If there is not a vertice for that word, creates one
            inserir_vertice(textos_a, word_a);
        }
        inserir_aresta(textos_a, word_a, word_b);//Creates an edge between the current word and the last one
        inserir_aresta(textos_a, word_b, word_a);
    }
    fclose(txt);
    txt = fopen("TEXT_1","r"); // Opening file in reading mode
    textos_b = criar_grafo();//Alloc space
    fscanf(txt,"%s",word_a);
    inserir_vertice(textos_b, word_a);//Insert the first vertice/word of the Graph
    memcpy(word_b, word_a, strlen(word_a));//copy the word to another variable
    while(fscanf(txt,"%s",word_a) != EOF){ //Reading all word_as in file
        if(buscar_vert(textos_b, word_a) == NULL){//If there is not a vertice for that word, creates one
            inserir_vertice(textos_b, word_a);
        }
        inserir_aresta(textos_b, word_a, word_b);//Creates an edge between the current word and the last one
        inserir_aresta(textos_b, word_b, word_a);
    }
    fclose(txt);
    imprime_grafo(textos_a);//print the graphs
    imprime_grafo(textos_b);
    return 0;
}
