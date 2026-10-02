#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define name_size 50
#define INITIAL_BACKPACK_CAPACITY 2

typedef struct item {
    char name[name_size];
} item;

typedef struct player {
    char name[name_size];
    int hp;
    int max_hp;
    int atk;
    int def;
    float resources;
    // struct backpack; fazer com vetor simples de tamanho definido, depois usar realloc para aumentar conforme ganha slots???
    item *backpack; 
    int backpack_capacity;
    int item_count;
} player;

typedef struct enemy {
    char name[name_size];
    int hp;
    int max_hp;
    int atk;
    int def;
    float resources;
} enemy;

// Prototipação de Funções (Declarações Prévias) já que C não possui hoisting que nem no javascript
void clean_buffer(void);
void init_player(player *p, const char *name, int hp, int atk, int def, float resources);
void free_player(player *p);
void show_backpack(const player *p);
void add_item_to_backpack(player *p, const char *item_name);
int main_menu(player *p);
void combat_menu(player *p);
void combat_turn_manager(player *p, enemy *m);
void remove_item_from_backpack(player *p, int index);
void init_enemy(enemy *m, const char *name, int hp, int atk, int def, float resources);
void reset_player(player *p, const char *name, int hp, int atk, int def, float resources);

// funções em si
void clean_buffer(void){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void init_player(player *p, const char *name, int hp, int atk, int def, float resources){
    strncpy(p->name, name, name_size - 1); // -1 por causa do último charactere que deve ser o '\0'
    p->name[name_size - 1] = '\0';
    p->hp = hp;
    p->max_hp = hp;
    p->atk = atk;
    p->def = def;
    p->resources = resources;
    p->backpack_capacity = INITIAL_BACKPACK_CAPACITY;
    p->item_count = 0;

    p->backpack = (item *) malloc(p->backpack_capacity * sizeof(item));
    if(p->backpack == NULL){
        fprintf(stderr, "\nerro ao alocar memória para a backpack\n");
        exit(EXIT_FAILURE);
    }
}

void init_enemy(enemy *m, const char *name, int hp, int atk, int def, float resources){
    strncpy(m->name, name, name_size - 1); // -1 por causa do último charactere que deve ser o '\0'
    m->name[name_size - 1] = '\0';
    m->hp = hp;
    m->max_hp = hp;
    m->atk = atk;
    m->def = def;
    m->resources = resources;
}

void free_player(player *p){
    if(p->backpack != NULL){
        free(p->backpack);
        p->backpack = NULL;
    }
}

void show_backpack(const player *p){
    printf("\nbackpack do player %s (%d/%d)SLOTS\n", p->name, p->item_count, p->backpack_capacity);

    if(p->item_count == 0){
        printf("\na backpack está vazia\n");
        return;
    }

    for(int i = 0; i < p->item_count; i++){
        printf("%d. %s\n", i+1, p->backpack[i].name);
    }
}

void add_item_to_backpack(player *p, const char *item_name){
    // adicionar comparação do nome do item; se for outra backpack, aí sim aumentar a capacidade
    if(p->item_count >= p->backpack_capacity){
        int new_capacity = p->backpack_capacity * 2;
        item *temp = (item *) realloc(p->backpack, new_capacity * sizeof(item));

        if(temp == NULL){
            printf("\nerro, não foi possível expandir a backpack\n");
            return;
        }

        p->backpack = temp;
        p->backpack_capacity = new_capacity;
        printf("\nbackpack expandida para %d SLOTS\n", new_capacity);
    }

    strncpy(p->backpack[p->item_count].name, item_name, name_size - 1);
    p->backpack[p->item_count].name[name_size - 1] = '\0';
    p->item_count++;

    printf("\nitem %s adicionado a mochila\n", item_name);
}

void remove_item_from_backpack(player *p, int index){
    if(index < 0 || index >= p->item_count){
        printf("\níndice de item inválido\n");

        return;
    }

    printf("\nitem %s consumido/removido\n", p->backpack[index].name);

    for(int i = index; i < p->item_count - 1; i++){
        p->backpack[i] = p->backpack[i+1];
    }

    p->item_count--;

    // realloc caso haja menos que metade dos slots ocupados
    if(p->item_count > 0 && p->item_count <= p->backpack_capacity / 2 && p->backpack_capacity > 5){
        int new_capacity = p->backpack_capacity / 2;
        item *temp = (item *) realloc(p->backpack, new_capacity * sizeof(item));

        if(temp != NULL){
            p->backpack = temp;
            p->backpack_capacity = new_capacity;
            
            printf("capacidade da backpack realocada para %d SLOTS", new_capacity);
        }
    }
}

void use_potion(player *p){
    int potion_index = -1;

    if(p->item_count == 0){
        printf("\nbackpack vazia\n");
        return;
    }

    for(int i = 0; i < p->item_count; i++){
        if(strstr(p->backpack[i].name, "potion") != NULL){
            potion_index = i;
            break;
        }
    }

    if(potion_index == -1){
        printf("\nnão há potion na backpack\n");
        return;
    }

    int heal_amount = 8;
    p->hp += heal_amount;

    if(p->hp > p->max_hp) p->hp = p->max_hp;

    printf("\npotion usada com sucesso, recuperando %d de hp, totalizando %d\n", heal_amount, p->hp);

    remove_item_from_backpack(p, potion_index);
}

void reset_player(player *p, const char *name, int hp, int atk, int def, float resources) {
    // 1. Liber a backpack da partida perdedora para evitar memory leak
    free_player(p);

    // 2. Reinicializar a struct e alocar uma backpack nova na Heap
    init_player(p, name, hp, atk, def, resources);
}

int main_menu(player *p){
    // player pode escolher avançar de sala, voltar para a sala, conferir inventário, lutar ou fugir
    int option = -1;
    int hp_inicial = p->hp;
    
    while(option != 0 && p->hp > 0){
        printf("xxxxxxxxxxGAME STATUSxxxxxxxxxxx\n\n");
        printf("player %s, hp %d, atk %d, def %d\n", p->name, p->hp, p->atk, p->def);
        printf("\nescolha uma opção\n");
        printf("\n0 - sair do jogo\n");
        printf("\n1 - avançar de sala\n");
        printf("\n2 - conferir backpack\n");
        printf("\n3 - usar potion\n");
        scanf("%d", &option);

        clean_buffer();

        switch (option)
        {
        case 0:
            printf("\nsaindo do jogo\n");
            
            break;
    
        case 1:
            printf("\navançando de sala\n");
            combat_menu(p);

            break;

        case 2:
            show_backpack(p);

            break;

        case 3:
            use_potion(p);

            break;
        
        default:
            printf("\nescolha uma opção válida\n");
            
            break;
        }
    }

    if(p->hp <= 0){
        printf("\ngame over\n");
        return 0; // Sinaliza que foi Game Over
    }

    return 1;
}

void combat_menu(player *p){
    enemy monstro;
    init_enemy(&monstro, "guardião", 20, 8, 8, 14.53);

    int combat_option = -1;

    while (combat_option != 0 && monstro.hp > 0 && p->hp > 0){
        printf("\num %s aparece! hp: %d, atk: %d, def: %d\n", monstro.name, monstro.hp, monstro.atk, monstro.def);
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
            combat_turn_manager(p, &monstro);

            break;

        default:
            printf("\nselecione uma opção válida\n");
            break;
        }
    }
}

void combat_turn_manager(player *p, enemy *m){
    int combat_turn_option = -1;

    while (combat_turn_option != 0 && p->hp > 0 && m->hp > 0){
        printf("\nTURNO DE COMBATE\n");
        printf("\n%s hp: %d, max_hp: %d. %s hp: %d, max_hp: %d\n", p->name, p->hp, p->max_hp, m->name, m->hp, m->max_hp);
        printf("\n0 - fugir e levar atk de %s\n", m->name);
        printf("\n1 - atacar %s\n", m->name);
        printf("\n2 - usar potion\n");
        printf("\n3 - conferir backpack\n");
        scanf("%d", &combat_turn_option);

        clean_buffer();

        switch (combat_turn_option)
        {
        case 0:
            printf("\nsaindo do combate com %d de dano do ataque do %s\n", m->atk, m->name);
            p->hp -= m->atk;

            if(p->hp < 0) p->hp = 0;

            break;

        case 1:
            // atk do player ao monstro
            int dano_causado = p->atk - m->def;
            if(dano_causado < 1) dano_causado = 1;
            m->hp -= dano_causado;

            printf("player %s provocou %d de dano ao %s\n", p->name, dano_causado, m->name);

            // verificar se monstro morreu
            if(m->hp <= 0){
                printf("player %s derrotou %s\n", p->name, m->name);

                add_item_to_backpack(p, "healing_potion\n");

                // substituir depois por um vetor com n itens e selecionar randomicamente um deles para ser o loot
                char nome_item[name_size];
                printf("dê um nome personalizado para o item\n");
                scanf("%49[^\n]", nome_item);
                clean_buffer();

                if(strlen(nome_item) > 0){
                    add_item_to_backpack(p, nome_item);
                }

                return;
            }

            // atk do monstro ao player
            int dano_recebido = m->atk - p->def;
            if(dano_recebido < 1) dano_recebido = 1;
            p->hp -= dano_recebido;
            printf("\no %s atacou, provocando %d de dano\n", m->name, dano_recebido);

            if(p->hp <= 0){
                printf("\nplayer %s derrotado! Game over...\n", p->name);
            }

            break;

        case 2:
            use_potion(p);

            break;

        case 3:
            show_backpack(p);

            break;
    
        default:
            printf("\nopção inválida\n");

            break;
        }
    }

    // ao vencer o monstro, a sala fica limpa e o player pode avançar de sala ou retornar
    
}

int main(){
    player acreano;
    
    // Status iniciais do jogador
    const char *nome = "acreano sama";
    int hp_base = 25;
    int atk_base = 3;
    int def_base = 5;
    float resources_base = 6.66f;

    // Primeira alocação
    init_player(&acreano, nome, hp_base, atk_base, def_base, resources_base);
    add_item_to_backpack(&acreano, "healing potion");

    int running = 1;
    while (running) {
        // Executa o menu do jogo
        int game_over = (main_menu(&acreano) == 0);

        if (game_over) {
            int option;
            printf("\nDeseja recomeçar o jogo? 0 - SIM, 1 - NÃO: ");
            scanf(" %d", &option);
            clean_buffer();

            switch (option){
                case 0:
                    printf("\n--- REINICIANDO O JOGO ---\n");

                    // Reseta a Heap e o HP com segurança
                    reset_player(&acreano, nome, hp_base, atk_base, def_base, resources_base);
                    add_item_to_backpack(&acreano, "healing potion");

                    break;
                
                case 1:
                    printf("\nObrigado por jogar!\n");
                    running = 0; // Encerra o loop principal

                    break;

                default:
                    break;
            }
        } else {
            // Jogador escolheu sair (opção 0 no menu)
            running = 0;
        }
    }
    
    // Limpeza final da memória
    free_player(&acreano);

    return 0;
}