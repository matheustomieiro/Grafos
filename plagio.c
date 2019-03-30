#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "grafo.c"

int main(int argc, char const *argv[]) {
    system ("python plagio.py"); // System call to run py script
    char word[255];
    int n = 2; // Two files will be compared
    FILE *txt;    
    txt = fopen("TEXT_0.txt","r"); // Opening file in reading mode
    for(int i=0; i<n; i++){
        while(fscanf(txt,"%s",word) != EOF){
            printf("%s\n",word);
        }
    fclose(txt);
    printf("\n\t\tNEW FILE\n");
    }
    return 0;
}
