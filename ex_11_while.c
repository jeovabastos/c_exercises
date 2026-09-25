#include <stdio.h>
#include <stdlib.h>

// usar while para simular um ataque especial de um jogo estilo final fantasy gameboy
// onde enquanto <condição> for verdadeira (ex: quantidade de mana) o ataque do mago continua no inimigo, faz sentido??

int main(){
    int mana = 10;
    int monstro_hp = 20;

    while (mana >= 0)
    {
        printf("mago ataca monstro! \n");
        printf("monstro_hp: %d\n", monstro_hp);
        printf("mana atual: %d\n", mana);

        mana--;
        monstro_hp--;
    }
    
    printf("acabou a mana! monstro_hp restante: %d\n", monstro_hp);
}

// próxima ideia: fazer um scanf para deixar o usuario decidir quanto de mana usar de cada vez