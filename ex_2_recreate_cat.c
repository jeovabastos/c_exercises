// O funcionamento base do cat resume-se a:

// Receber o caminho de um ou mais arquivos via linha de comando (ou da entrada padrão stdin).
// Abrir cada arquivo.
// Ler o conteúdo aos poucos (em pedaços/buffers) até o final do arquivo (EOF).
// Escrever cada pedaço lido na saída padrão (stdout).
// Fechar o arquivo e tratar erros básicos (ex: arquivo não existe).

// Passo 1: Entendendo os Argumentos (argc e argv)
// Para receber o nome do arquivo pelo terminal, a função main precisa dos parâmetros int argc (quantidade de argumentos) e char *argv[] (lista de textos com os argumentos).

// argv[0] é sempre o nome do seu executável (ex: ./meu_cat).
// argv[1] será o primeiro arquivo passado (ex: arquivo.txt).

#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 512

void processar_arquivo(const char *caminho){
    FILE *arquivo = fopen(caminho, "r");

    if(arquivo == NULL){
        fprintf(stderr, "cat: %s: Não foi possível abrir o arquivo\n", caminho);
        return;
    }

    char buffer[BUFFER_SIZE];
    
    while(fgets(buffer, sizeof(buffer), arquivo) != NULL){
        fputs(buffer, stdout);
    }

    fclose(arquivo);
}

int main(int argc, char *argv[]){
    // argv[0] é o próprio programa, então argv precisa ser pelo menos 2
    if(argc < 2){
        printf("Uso: %s <nome_do_arquivo>\n", argv[0]);
        return 1;
    }

    for(int i = 1; i < argc; i++){
        processar_arquivo(argv[1]);
    }

    return EXIT_SUCCESS;
}