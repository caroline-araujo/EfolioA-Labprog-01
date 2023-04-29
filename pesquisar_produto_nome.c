#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include "pesquisar_produto.h"
#include "menu.h"
#include "structs.h"

void pesquisar_produto_nome (struct produtos produto[], int *num_produtos) {
    FILE *estoque = fopen ("estoque.csv", "r"); //Abrindo um arquivo para leitura dos produtos

    if (estoque == NULL) { //Verifica se o arquivo foi aberto com sucesso
        printf ("Erro ao abrir o arquivo\n");
        return;
    }

    char nomepesquisado[100];

    printf ("Digite o nome do produto que deseja pesquisar: ");
    fgets (nomepesquisado, 100, stdin);

    // Verifica se o ultimo caractere da string e \n e substitui por \0, se necessario
    if (nomepesquisado[strlen(nomepesquisado) - 1] == '\n') {
        nomepesquisado[strlen(nomepesquisado) - 1] = '\0';
    }

    char linha[100];
    int encontrado = 0;

    while (fgets(linha, sizeof(linha), estoque)) {
        struct produtos produto_arquivo;
        sscanf(linha, "%d,%[^,],%d,%f", &produto_arquivo.codigo, produto_arquivo.produto, &produto_arquivo.quantidade, &produto_arquivo.preco);

    for (int i = 0; i < *num_produtos; i++) {
        if (strcmp(produto[i].produto, nomepesquisado) == 0) { //Usando o strcmp pra percorrer o vetor de produtos e comparar o nome de cada produto com a string nomepesquisado
            printf ("Produto encontrado! Produto: %d, %s, %d, %.2f\n", produto[i].codigo, produto[i].produto, produto[i].quantidade, produto[i].preco);
            encontrado = 1;
        }
    }
    }
    // Se o produto nao foi encontrado, imprime a mensagem correspondente
    if (!encontrado) {
        printf ("Produto n�o encontrado\n");
    }

    fclose(estoque);
    menu();
}

