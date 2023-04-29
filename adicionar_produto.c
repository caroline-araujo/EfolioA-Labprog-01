#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include "adicionar_produto.h"
#include "menu.h"
#include "structs.h"

void adicionar_produto(struct produtos produto[], int *num_produtos) {
    FILE *estoque = fopen("estoque.csv", "r+"); //Abre o arquivo para leitura e escrita

    if (estoque == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    struct produtos novoProduto;

    printf("Digite o codigo do produto: ");
    scanf("%d", &novoProduto.codigo);

    printf("Digite o nome do produto: ");
    getchar();
    fgets(novoProduto.produto, MAX_PRODUTOS, stdin);
    novoProduto.produto[strcspn(novoProduto.produto, "\n")] = '\0'; // Remove o caractere de nova linha lido pelo fgets

    printf("Digite a quantidade do produto: ");
    scanf("%d", &novoProduto.quantidade);

    printf("Digite o preco do produto: ");
    scanf("%f", &novoProduto.preco);

    char linha[MAX_PRODUTOS];
    int encontrou = 0;

    while (fgets(linha, MAX_PRODUTOS, estoque) != NULL) {
        struct produtos p;
        sscanf(linha, "%d, %[^,], %d, %f", &p.codigo, p.produto, &p.quantidade, &p.preco);

        if (p.codigo == novoProduto.codigo) {
            encontrou = 1;
            p.quantidade += novoProduto.quantidade;
            fseek(estoque, -strlen(linha), SEEK_CUR); // volta para o inicio da linha atual
            fprintf(estoque, "%d, %s, %d, %.2f\n", p.codigo, p.produto, p.quantidade, p.preco);
            break;
        }
    }

    if (!encontrou) {
        fprintf(estoque, "%d, %s, %d, %.2f\n", novoProduto.codigo, novoProduto.produto, novoProduto.quantidade, novoProduto.preco);
    }

    fclose(estoque);

    produto[*num_produtos] = novoProduto;
    (*num_produtos)++;
    menu();
}
