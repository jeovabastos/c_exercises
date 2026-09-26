#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 5

void limpar_buffer(void){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main(){
    char backpack[MAX_ITENS][20] = {""};
    char target[20] = "";
    int option = -1;

    while (option != 0){
        printf("\n SUA BACKPACK: \n");
        printf("1 - adicionar item \n");
        printf("2 - procurar item \n");
        printf("3 - listar itens \n");
        printf("0 - sair do inventário \n");
        printf("escolha uma opção \n");            
        
        if(scanf("%d", &option) != 1){
            limpar_buffer();
            continue;
        }
    
        limpar_buffer();
    
        switch (option){
            case 1:
                // adicionar item
                int adicionado = 0;
                for (int i = 0; i < MAX_ITENS; i++){
                    if(backpack[i][0] == '\0'){
                        printf("nome do item a adicionar: \n");
                        scanf("%19s", backpack[i]);
                        limpar_buffer();
            
                        printf("'%s' adicionado a backpack na posição [%d]\n", backpack[i], i);
                        adicionado = 1;
                        break;
                    }
                }

                if (!adicionado) {
                    printf("\n-> A mochila esta cheia! (Max: %d itens)\n", MAX_ITENS);
                }
        
                break;
            
            case 2:
                // procurar item
                printf("que item gostaria de procurar? \n");
                scanf("%19s", target);
        
                printf("procurando item %s no inventário... \n", target);
                int encontrado = 0;
                for(int i = 0; i < MAX_ITENS; i++){
                    printf(".\n");
        
                    if(backpack[i] != NULL && strcmp(backpack[i], target) == 0){
                        printf("%s encontrado! \n", target);
                        encontrado = 1;
                        break;
                    }
                }
        
                if (!encontrado) {
                    printf("-> Item '%s' não encontrado na mochila T.T\n", target);
                }
                break;

            case 3:
                printf("lista de itens: \n");
                for(int i = 0; i < MAX_ITENS; i++){
                    if(backpack[i][0] != '\0'){
                        printf("%s na posição %d \n", backpack[i], i);
                    }else{
                        printf("slot '%d' vazio \n", i);
                    }
                }

            case 0:
                printf("fechando a backpack \n");
                break;  
        
            default:
                printf("opção inválida \n");
                break;
        }
    }

    return 0;
}