#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// forma de declarar struct
struct player
{
    char nome[50];
    int atk;
    float recursos;
};

// forma de simplificar a instanciação da struct com um apelido
typedef struct player player;

// forma de definir a struct e o typedef para simplificar a instanciação da struct
typedef struct enemy {
    char nome[50];
    int atk;
    int def;
    float drop_recursos;
} enemy;

int main(){
    player acreano = {
        "acreanosama",
        6,
        1621.98
    };

    printf("acreano.nome: %s \n", acreano.nome);
    printf("acreano.atk: %d \n", acreano.atk);
    printf("acreano.recursos: %.2f \n", acreano.recursos);

    player vera;
    strcpy(vera.nome, "vera von stral");
    vera.atk = 4;
    vera.recursos = 8942.61;

    printf("vera.nome: %s \n", vera.nome);
    printf("vera.atk: %d \n", vera.atk);
    printf("vera.recursos: %.2f \n", vera.recursos);

    enemy quetzal = {
        "guardião vassalo quetzal",
        8,
        16,
        666.98
    };

    printf("quetzal.nome: %s \n", quetzal.nome);
    printf("quetzal.atk: %d \n", quetzal.atk);
    printf("quetzal.def: %d \n", quetzal.def);
    printf("quetzal.drop_recursos: %.2f \n", quetzal.drop_recursos);
}