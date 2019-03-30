#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "grafo.c"

int main(int argc, char const *argv[]) {
    system ("python plagio.py"); // System call to run py script
    char word[255];
    FILE *txt;    
    txt = fopen("TEXT_0.txt","r");
    while(fscanf(txt,"%s",word) != EOF){
        printf("%s",word);
    }
    fclose(txt);
    return 0;
}
