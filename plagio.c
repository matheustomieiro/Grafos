#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "grafo.c"

int main(int argc, char const *argv[]) {
    system ("python plagio.py"); // System call to run py script
    char word[255];
    char filename[255];
    int n = 2; // Two files that will be compared
    FILE *txt;    
    for(int i=0; i<n; i++){ // Running for_loop 'n' times
        sprintf(filename, "TEXT_%d.txt", i);
        txt = fopen(filename,"r"); // Opening file in reading mode
        while(fscanf(txt,"%s",word) != EOF){ //Reading all words in file
            printf("%s\n",word); // Just showing. Need to add 'grafo.c'
        }
    fclose(txt);
    printf("\n\t\tEND\n");
    }
    return 0;
}
