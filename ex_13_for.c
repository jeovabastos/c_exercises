#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 5 // jeito mais simples que achei para usar o tamanho da array como controle do FOR

int main(){
    char *itens[MAX_ITENS] = {"sword", "healing_potion", "backpack", "shield", "clothes"};

    printf("todos os itens do inventario: \n");

    for(int i = 0; i < MAX_ITENS; i++){
        printf("%s\n", itens[i]);
    }

    printf("\né isso :'3\n");
    return 0;
}