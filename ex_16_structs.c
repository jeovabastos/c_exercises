#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    struct player
    {
        char nome[20];
        int atk;
        float recursos;
    };
    
    typedef struct player player;

    player acreano = {
        "acreanosama",
        6,
        1621.98
    };

    printf("acreano.nome: %s \n", acreano.nome);
    printf("acreano.atk: %d \n", acreano.atk);
    printf("acreano.recursos: %.2f \n", acreano.recursos);
}