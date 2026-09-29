#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void renderizar_ascii_art(const char *caminho_arquivo){
    FILE *arquivo = fopen(caminho_arquivo, "r");

    if(arquivo == NULL){
        printf("erro ao abrir arquivo %s \n", caminho_arquivo);
        return;
    }

    int c;
    while((c = fgetc(arquivo)) != EOF){
        putchar(c);
    };

    fclose(arquivo);
}

int main(){
    system("clear");
    printf("\nvisualizador de ascii_art \n\n");

    renderizar_ascii_art("ascii-art.txt");

    printf("\n\n");
    return 0;
}