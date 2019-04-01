#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafolista.h"
#define MAX 2


int main(int argc, char const *argv[]) {
    system ("python plagio.py"); // System call to run py script
    char word_a[255], word_b[255];
    char filename[255];
    int n = 2; // Two files that will be compared
    Grafo textos[MAX];// Declare an array os the struct Grafo
    FILE *txt;    
    for(int i=0; i<n; i++){ // Running for_loop 'n' times
        sprintf(filename, "TEXT_%d.txt", i);
        txt = fopen(filename,"r"); // Opening file in reading mode
        textos[i] = criar_grafo();//Alloc space
        fscanf(txt,"%s",word_a);
        inserir_vertice(textos[i], word_a);//Insert the first vertice/word of the Graph
        memcpy(word_b, word_a, strlen(word_a));//copy the word to another variable
        while(fscanf(txt,"%s",word_a) != EOF){ //Reading all word_as in file
            if(buscar_vert(textos[i], word_a) == NULL){//If there is not a vertice for that word, creates one
                inserir_vertice(textos[i], word_a);
            }
            inserir_aresta(textos[i], word_a, word_b);//Creates an edge between the current word and the last one
            inserir_aresta(textos[i], word_b, word_a);
        }
        fclose(txt);
    }
    for(int i=0; i<n; i++){
        imprime_grafo(textos[i]);//print the graphs
    }
    return 0;
}
