#include <stdio.h>
#include <stdlib.h>

void compactar_arquivo(int argc, char *argv[]){
    int count = 0;
    int current_character = EOF;
    int next_char;

    for(int i = 1; i < argc; i++){
        FILE *fp = fopen(argv[i], "r");

        if(fp == NULL){
            printf("Não foi possivel abrir o arquivo");
            exit(EXIT_FAILURE);
        }

        while((next_char = fgetc(fp)) != EOF){
            if(current_character == EOF){
                current_character = next_char;
                count = 1;
            }else if(next_char == current_character){
                count++;
            }else{
                fwrite(&count, sizeof(int), 1, stdout);
                fwrite(&current_character, sizeof(char), 1, stdout);

                current_character = next_char;
                count = 1;
            }
        }

        fclose(fp);
    }

    if(current_character != EOF){
        fwrite(&count, sizeof(int), 1, stdout);
        fwrite(&current_character, sizeof(char), 1, stdout);
    }
}

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("Uso: %s <nome_arquivo>\n", argv[0]);

        return EXIT_FAILURE;
    }
    
    compactar_arquivo(argc, argv);

    return EXIT_SUCCESS;
}