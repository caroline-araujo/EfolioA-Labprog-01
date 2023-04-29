#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include "pesquisar_produto.h"
#include "menu.h"
#include "structs.h"

void pesquisar_produto_codigo(struct produtos produto[], int *num_produtos) {
    FILE *estoque = fopen("estoque.csv", "r"); // Abrindo o arquivo para leitura dos produtos restantes

    if (estoque == NULL) { // Verifica se o arquivo foi aberto com sucesso
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    int codigopesquisado;
    printf("Digite o numero do codigo que deseja pesquisar: ");
    scanf("%d", &codigopesquisado);

    char linha[100];
    int encontrado = 0;

    // Lê cada linha do arquivo CSV e verifica se o código corresponde ao código pesquisado
    while (fgets(linha, sizeof(linha), estoque)) {
        struct produtos produto;
        sscanf(linha, "%d,%[^,],%d,%f", &produto.codigo, produto.produto, &produto.quantidade, &produto.preco);

        if (produto.codigo == codigopesquisado) {
            printf("Produto encontrado! Produto: %d, %s, %d, %.2f\n", produto.codigo, produto.produto, produto.quantidade, produto.preco);
            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0) { // Se o produto não foi encontrado, exibe a mensagem de erro
        printf("Codigo nao encontrado\n");
    }

    fclose(estoque);

    menu();
}


