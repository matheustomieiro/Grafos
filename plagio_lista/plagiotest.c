#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafolista.h"
#define MAX 2


int main(int argc, char const *argv[]) {
    system ("python plagio.py"); // System call to run py script
    char word_a[25], word_b[25];

    //char filename[255];
    //int n = 2; // Two files that will be compared

    Grafo *texto_a, *texto_b;// Declare an array os the struct Grafo
    FILE *txt;    
    txt = fopen("TEXT_0.txt","r"); // Opening file in reading mode
    texto_a = criar_grafo();//Alloc space
    fscanf(txt, "%s", word_a);
    inserir_vertice(texto_a, word_a);//Insert the first vertice/word of the Graph
    strcpy(word_b, word_a);//copy the word to another variable
    while(fscanf(txt,"%s",word_a) != EOF){ //Reading all word_as in file
        if(buscar_vert(texto_a, word_a) == NULL){//If there is not a vertice for that word, creates one
            inserir_vertice(texto_a, word_a);
        }
        inserir_aresta(texto_a, word_a, word_b);//Creates an edge between the current word and the last one
        inserir_aresta(texto_a, word_b, word_a);
        strcpy(word_b, word_a);//copy the word to another variable
    }
    fclose(txt);
    txt = fopen("TEXT_1.txt","r"); // Opening file in reading mode
    texto_b = criar_grafo();//Alloc space
    fscanf(txt,"%s",word_a);
    inserir_vertice(texto_b, word_a);//Insert the first vertice/word of the Graph
    strcpy(word_b, word_a);//copy the word to another variable
    while(fscanf(txt,"%s",word_a) != EOF){ //Reading all word_as in file
        if(buscar_vert(texto_b, word_a) == NULL){//If there is not a vertice for that word, creates one
            inserir_vertice(texto_b, word_a);
        }
        inserir_aresta(texto_b, word_a, word_b);//Creates an edge between the current word and the last one
        inserir_aresta(texto_b, word_b, word_a);
        strcpy(word_b, word_a);//copy the word to another variable
    }
    fclose(txt);
    imprime_grafo(texto_a);//print the graphs
    imprime_grafo(texto_b);
    return 0;
}
