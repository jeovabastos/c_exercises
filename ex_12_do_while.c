#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// continuando a ideia de um jogo de terminal, um certo npc requer uma mensagem/senha para liberar um item
// o usuario/jogador tem que acertar a senha e pode tentar até 3 vezes

void limpar_buffer(void){
    int c;
    // Limpa qualquer caractere excedente que tenha sobrado no buffer stdin
    // (caso o jogador digite mais do que 4 letras)
    while ((c = getchar()) != '\n' && c != EOF); // itera pelo buffer do teclado até encontrar \n, limpando o buffer
}

int main(){
    // 5 por causa do espaço necessário nulo ao fim da array, 4 para "azul" + 1 para nulo "\0"
    char palavra_secreta[5] = "azul";
    char senha[5] = "";
    int tentativas = 3;
    
    do{
        // senha = "";
        printf("qual é a senha nobre cavaleiro??? (Tentativas restantes: %d)\n", tentativas);
        scanf("%4s", senha); // 4 por causa do tamanho da senha em si

        limpar_buffer();

        if(strcmp(senha, palavra_secreta) == 0){
            printf("senha correta, aqui o item!\n");
            return 0;
        }

        tentativas--;

        if(tentativas > 0){
            printf("senha incorreta, tente novamente\n");
        }

    }while(tentativas > 0);
    
    printf("você errou 3 vezes, o npc foi embora \n");
    return 0;
}