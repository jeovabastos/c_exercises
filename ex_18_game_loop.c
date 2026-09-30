#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define name_size 50

// Prototipação de Funções (Declarações Prévias) já que C não possui hoisting que nem no javascript
void clean_buffer(void);
void main_menu(void);
void combat_menu(void);
void combat_turn_manager(void);

// dungeon crawler
// structs das entidades, da sala e dos itens
// menu de opções
// sistema de turnos de combate
// dados salvos apenas em memória por enquanto

typedef struct player {
    char name[name_size];
    int atk;
    int def;
    float resources;
    // struct backpack; fazer com vetor simples de tamanho definido, depois usar realloc para aumentar conforme ganha slots???
} player;

typedef struct room {
    char name[name_size];
} room;

void clean_buffer(void){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void main_menu(void){
    // player pode escolher avançar de sala, voltar para a sala, conferir inventário, lutar ou fugir
    int option = -1;
    
    while(option != 0){
        printf("\nescolha uma opção\n");
        printf("\n0 - sair do jogo\n");
        printf("\n1 - avançar de sala\n");
        // printf("\n\n");
        scanf("%d", &option);

        clean_buffer();

        switch (option)
        {
        case 0:
            printf("\nsaindo do jogo\n");
            break;
    
        case 1:
            printf("\navançando de sala\n");
            combat_menu();

            break;
        
        default:
            printf("\nescolha uma opção válida\n");
            break;
        }
    }
}

void combat_menu(void){
    int combat_option = -1;

    while (combat_option != 0){
        printf("\num monstro aparece!\n");
        printf("\no que fazer? 0 - voltar para sala anterior, 1 - lutar!\n");
        scanf("%d", &combat_option);
        
        clean_buffer();

        switch (combat_option)
        {
        case 0:
            printf("\nretornando para sala segura!\n");

            break;
        
        case 1:
            printf("\nentrando em modo de combate!\n");
            combat_turn_manager();

            break;

        default:
            printf("\nselecione uma opção válida\n");
            break;
        }
    }
}

void combat_turn_manager(void){
    int combat_turn_option = -1;

    while (combat_turn_option != 0){
        printf("\ncombate contra monstro_xyz, o que vai fazer?\n");
        printf("\n0 - fugir e levar atk de monstro_xyz\n");
        printf("\n1 - atacar monstro_xyz\n");
        printf("\n2 - conferir backpack\n");
        scanf("%d", &combat_turn_option);

        clean_buffer();

        switch (combat_turn_option)
        {
        case 0:
            printf("\nsaindo do combate com xyz de dano do ataque do monstro_xyz\n");
            break;

        case 1:
            printf("\nvocê atacou o monstro, provocando xyz de dano a ele\n");
            break;

        case 2:
            printf("\nconferindo a backpack\n");
            break;
    
        default:
            break;
        }
    }
    
}

int main(){
    // menu switch
    main_menu();

    return 0;
}