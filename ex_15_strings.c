#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 30

void limpar_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

int main(){
    char nome[MAX_SIZE] = "";
    char temp[MAX_SIZE] = "";
    
    // manipular strings usando estruturas mais completas do C, como a sequência %s[^\n] para espaços em branco
    printf("\ndigite seu nome completo: \n");
    scanf("%19[^\n]", nome); // MAX_SIZE - 1
    limpar_buffer();

    // concatenar strings
    strcpy(temp, "lord "); // inserindo a string 'lord' em endereço temporario
    strcat(temp, nome); // concatenando as strings lord e 'nome'
    strcpy(nome, temp); // inserindo a string 'temp' no lugar de 'nome'
    printf("\nseu novo título: %s \n", nome);

    // substituir valor de strings
    printf("\nalternativa, substituir o valor de nome: \n");
    char novo_nome[MAX_SIZE] = "";
    scanf("%19[^\n]", novo_nome);
    limpar_buffer();

    strcpy(nome, novo_nome);
    printf("novo_nome agora é: %s \n", nome);

    // usando strlen para adquirir o tamanho de strings
    char frase[MAX_SIZE];
    int tamanho_frase;

    puts("digite uma frase");
    gets(frase);

    tamanho_frase = strlen(frase);
    printf("tamanho da frase digitada é: %d", tamanho_frase);
}