#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include "listar_produtos.h"
#include "menu.h"
#include "structs.h"

void listar_produtos(struct produtos produto[], int *num_produtos) {
    FILE *estoque = fopen("estoque.csv", "r");

    if (estoque == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    printf("Produtos:\n");

    while (!feof(estoque)) {
        struct produtos produto_arquivo;
        fscanf(estoque, "%d,%[^,],%d,%f", &produto_arquivo.codigo, produto_arquivo.produto, &produto_arquivo.quantidade, &produto_arquivo.preco);

        if (feof(estoque)) {
            break;
        }

        printf("%d, %s, %d, %.2f\n", produto_arquivo.codigo, produto_arquivo.produto, produto_arquivo.quantidade, produto_arquivo.preco);
    }

    fclose(estoque);
    menu ();
}
