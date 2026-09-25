#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void processar_arquivo(const char *termo, FILE *arquivo){
    if(arquivo == NULL){
        printf("Não foi possível abrir o arquivo");
        return;
    }
    
    char buffer[BUFFER_SIZE];

    while(fgets(buffer, sizeof(buffer), arquivo) != NULL){
        if(strstr(buffer, termo) != NULL){
            fputs(buffer, stdout);
        }
    }
}

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Uso %s <termo_de_busca> e <nome_do_arquivo> ou apenas <termo_de_busca>\n", argv[0]);
        return 1;
    }

    // argv[0] é o programa
    // argv[1] é o termo
    // argv[2] em diante são os arquivos
    for(int i = 2; i < argc; i++){
        FILE *fp = fopen(argv[i], "r");

        if(fp == NULL){
            printf("Cannot open %s\n", argv[i]);
            return EXIT_FAILURE;
        }

        processar_arquivo(argv[1], fp);
        fclose(fp);
    }

    return EXIT_SUCCESS;
}