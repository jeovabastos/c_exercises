# Plano de estudos para aprender o mínimo indispensável de C

# 1. Pipeline de Compilação e Organização do Projeto

- Pré-processador: Substituição textual via diretivas (`#include`, `#define`, `#ifdef`) e o uso de _Include Guards_ (`#ifndef` ou `#pragma once`).
- Separação de arquivos: Separação entre interface (`.h`) e implementação (`.c`).
- Estágios do Pipeline: Entender o fluxo _Pré-processamento $\rightarrow$ Compilação $\rightarrow$ Assembly $\rightarrow$ Linkagem_ (arquivos `.o`, bibliotecas e executável final).
# 2. Ponteiros, Endereçamento e Ponteiros Especiais
- Operadores Básicos: `&` (obter endereço) e `*` (desreferenciar/acessar valor) para passagem de parâmetros por referência.
- Aritmética de Ponteiros: Avançar e recuar na memória respeitando a largura em bytes do tipo do dado
- Ponteiros Duplos (`**p`): Uso em alocação de matrizes dinâmicas e para alterar ponteiros dentro de funções.
- Ponteiros para Funções: Passagem de comportamento como argumento (callbacks e tabelas de despacho).
# 3. Modelo e Gerenciamento Manual de Memória
- Stack vs. Heap: Compreender o tempo de vida e escopo das variáveis locais automáticas (Stack) versus alocações em tempo de execução (Heap).
- Alocação e Liberação (`<stdlib.h>`): Uso de `malloc`, `calloc`, `realloc` e a obrigatoriedade do `free`.
- Erros de Memória Comuns: Evitar _Memory Leaks_ (falta de `free`), _Dangling Pointers_ (ponteiros para memória já liberada), _Use-After-Free_ e _Segmentation Faults_.
# 4. Arrays, Strings e Decaimento
- Arrays: Alocação contígua de memória e o conceito de _array decay_ (conversão implícita do array para ponteiro no primeiro elemento).
- Strings: Arrays de `char` terminados obrigatoriamente no caractere nulo (`\0`).
- Manipulação Segura: Uso das funções de `<string.h>` (`strlen`, `strcpy`, `strcmp`, `strcat`) e prevenções contra _Buffer Overflow_.
# 5. Tipos Customizados e Layout de Memória (Structs)
- `struct` e `union`: Agrupamento de dados, uso do operador `.` (instância direta) e `->` (via ponteiro), além de `typedef` para aliases.
- Alinhamento e Padding: Como o compilador insere bytes invisíveis na `struct` para otimizar o acesso à memória pelo processador.
# 6. Comportamento Indefinido (Undefined Behavior - UB)
- O perigo silencioso do C: Entender que erros de lógica muitas vezes não geram alertas de compilação, resultando em binários imprevisíveis.
- Gatilhos clássicos de UB: Acesso fora dos limites do array, leitura de variáveis não inicializadas, _overflow_ de inteiros assinados e desreferenciamento de ponteiros nulos (`NULL`).
# 7. Entrada/Saída e Manipulação de Arquivos
- I/O Padrão (`<stdio.h>`): `printf`, a fragilidade de `scanf` e a preferência por `fgets` para leitura segura de buffers.
- I/O de Arquivos: Modos texto e binário para abertura, leitura, escrita e fechamento de streams (`fopen`, `fread`, `fwrite`, `fclose`).

# projetos
Para fixar os 7 tópicos (Memória, Ponteiros, Alocação Dinâmica, Estruturas de Dados, Pré-processador, Erros de Execução e Arquivos), o ideal é criar projetos progressivos, onde cada um exige que você consolide os aprendizados do anterior sem depender de bibliotecas externas.
Sequência de 4 projetos práticos, do básico ao avançado, estruturados para cobrir cada conceito:

# Manipulador de Imagens PGM em Binário
Um leitor e processador de imagens simples no formato PGM (Portable Gray Map). O PGM em formato binário é perfeito para entender como computadores lidam com dados puros.

O que você vai aplicar:

Manipulação de Arquivos (fopen, fread, fwrite): Ler o cabeçalho do arquivo texto e extrair a matriz de pixels em formato binário.
Ponteiros e Alocação Dinâmica (malloc, free): Criar a matriz/array de pixels dinamicamente na memória RAM dependendo da largura e altura da imagem.
structs e Tipagem: Criar uma struct Imagem contendo largura, altura, valor máximo de cinza e o ponteiro para os pixels.
Desafio prático: Criar funções para aplicar filtros na imagem (ex: inverter as cores, escurecer/clarear) passando a estrutura via ponteiro e gerando um novo arquivo de saída.

# Gerenciador de Registros/Banco de Dados Simples
Um sistema de linha de comando para cadastrar, buscar, editar e deletar registros (por exemplo, um catálogo de produtos, livros ou personagens de um jogo).

O que você vai aplicar:

structs e Layout de Memória: Definir os dados do registro e entender o alinhamento de memória.
Ponteiros de Função: Usar ponteiros de função para criar sistemas de ordenação ou filtros genéricos (ex: passar uma função comparadora para ordenar a lista por código, nome ou preço).
Arquivos e Persistência: Salvar e carregar a base de dados do disco em arquivo binário para que as informações não se percam ao fechar o programa.
Organização em Múltiplos Arquivos: Separar o projeto em main.c, db.c, db.h usando Include Guards (#ifndef).
Desafio prático: Garantir que o programa não feche ou corrompa os dados se o usuário digitar uma entrada inválida (como texto onde deveria ser um número).

# Clone Simples do grep ou Utilitário de Texto
Uma ferramenta de linha de comando que busca por palavras ou padrões dentro de arquivos de texto grandes e exibe as linhas onde eles aparecem.

O que você vai aplicar:

Arrays, Strings e \0: Manipular strings de baixo nível, calculando tamanhos, buscando caracteres e lidando com quebras de linha sem estourar o buffer.
Prevenção de Undefined Behavior: Garantir que linhas mais longas do que o esperado não causem Buffer Overflow (usando fgets de forma segura em vez de gets/scanf).
Uso da Stack vs Heap: Saber onde alocar buffers temporários de leitura sem estourar a pilha de execução.
Desafio prático: Aceitar argumentos passados diretamente pelo terminal via int main(int argc, char *argv[]) para definir o arquivo e o termo de busca.

# Coletor de Lixo/Alocador de Memória Customizado ou Lista Dinâmica Genérica
Construir uma estrutura de dados totalmente flexível (como uma Lista Encadeada ou um Vetor Dinâmico similar ao std::vector de C++) capaz de armazenar qualquer tipo de dado.

O que você vai aplicar:
Ponteiros Opacos/Genéricos (void*): Permitir que a estrutura guarde inteiros, textos ou structs customizadas usando ponteiros genéricos.
Gerenciamento Manual Estrito de Memória: Usar realloc para dobrar a capacidade do vetor quando ele encher e garantir que 100% da memória seja liberada no final com free.
Aritmética de Ponteiros: Deslocar-se manualmente pela memória com base no tamanho do tipo do dado (sizeof).
Detecção de Memory Leaks: Rodar o programa com ferramentas como o Valgrind ou AddressSanitizer para provar que zero bytes de memória foram vazados.