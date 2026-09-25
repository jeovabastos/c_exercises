#include <stdio.h>
#include <stdlib.h>

int main(){
    // um seletor/editor de personagem utilizando o switch case

    int nome_personagem = 0;

    printf("escolha seu personagem:\n");
    printf("1 - minerva \n");
    printf("2 - lucy \n");
    scanf("%d", &nome_personagem);

    switch (nome_personagem)
    {
    case 1:
        printf("você escolheu minerva \n");
        break;

    case 2:
        printf("você escolheu lucy \n");
        break;
    
    default:
        printf("seu personagem será pythia \n");
        break;
    }

    // obs: tentei usar strings literais nos case mas o C não permite isso, então tive que usar um menu mesmo com os números das opções
}