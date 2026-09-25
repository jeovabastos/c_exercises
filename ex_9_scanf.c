#include <stdio.h>
#include <stdlib.h>

int main(){
    int idade = 0;
    float salario = 0.0;
    char nome[20] = "";

    printf("digite sua idade: \n");
    scanf("%d", &idade);

    printf("digite seu salario: \n");
    scanf("%f", &salario);
 
    printf("digite seu nome: \n");
    scanf("%s", nome);

    // 3. Leitura Segura de Strings (scanf vs fgets)
    // O scanf("%s", nome) possui dois riscos graves:
    // Buffer Overflow: Se o usuário digitar mais de 19 caracteres, o scanf escreverá fora do limite do array. Para evitar isso com scanf, limite o tamanho: scanf("%19s", nome);.
    // Espaços em branco: O %s para de ler no primeiro espaço. Se você digitar "João Silva", ele lerá apenas "João". Para ler nomes compostos com segurança, prefira o fgets:
    // fgets(nome, sizeof(nome), stdin);

    if(idade > 0 && salario > 0.0 && nome[0] != '\0'){
        printf("idade informada: %d \n", idade);
        printf("salario informado: %.2f \n", salario);
        printf("seu nome é: %s \n", nome);
        exit(0);
    }

    printf("informe idade e salario maior que zero \n");
    exit(1);
}