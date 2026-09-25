#include <stdio.h>
#include <stdlib.h>

void descompactar(FILE *fp){
    int count;
    char pixel;

    while(fread(&count, sizeof(int), 1, fp) == 1){
        if(fread(&pixel, sizeof(char), 1, fp) != 1){
            break;
        }

        for(int i = 0; i < count; i++){
            fputc(pixel, stdout);
        }
    }

    fputs("\n", stdout);
}

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Uso: %s <nome_arquivo>\n", argv[0]);
        return EXIT_FAILURE;
    }

    for(int i = 1; i < argc; i++){
        FILE *fp = fopen(argv[i], "r");
        
        if(fp == NULL){
            printf("Não foi possivel abrir o arquivo\n");
            return EXIT_FAILURE;
        }

        descompactar(fp);
        fclose(fp);
    }

    return EXIT_SUCCESS;
}