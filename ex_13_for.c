#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 5 // jeito mais simples que achei para usar o tamanho da array como controle do FOR

int main(){
    char *itens[MAX_ITENS] = {"sword", "healing_potion", "backpack", "shield", "clothes"};
    char target[20] = "";

    printf("que item gostaria de procurar??? \n");
    scanf("%20s", target);

    printf("procurando %s no inventario: \n", target);

    for(int i = 0; i < MAX_ITENS; i++){
        // printf("%s\n", itens[i]);
        printf(".\n");

        if(strcmp(itens[i], target) == 0){
            printf("%s encontrado! \n", target);
            return 0;
        }
    }

    printf("\n item não encontrado T.T \n");
    return 0;
}