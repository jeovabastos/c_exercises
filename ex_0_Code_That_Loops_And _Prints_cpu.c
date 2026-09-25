#include <stdio.h>
#include <stdlib.h>

// imprime um character infinitamente
// modo de uso: gcc ex_0_Code_That_Loops_And\ _Prints_cpu.c -o ex_0 && ./ex_0 "a"

// A entrada vem da main: Quando você executa ./ex_0 "a", o sistema operacional envia o caractere "a" para o vetor argv[1] na inicialização do programa.
// A variável guarda o valor: A linha char *str = argv[1] armazena o endereço desse caractere na variável str.
// O while (1) é só um controle: O 1 significa verdadeiro, criando apenas uma repetição infinita do bloco sem processar nenhum dado.
// O printf relê a memória: A cada ciclo, o printf busca o caractere na variável str (que continua salva na memória) e o envia para o terminal.

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: cpu <string>\n");
        exit(1);
    }
    char *str = argv[1];
    while (1)
    {
        printf("%s\n", str);
    }
    return 0;
}