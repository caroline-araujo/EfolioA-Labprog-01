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

    while (fscanf(estoque, "%d,%[^,],%d,%f", &produto[*num_produtos].codigo, produto[*num_produtos].produto, &produto[*num_produtos].quantidade, &produto[*num_produtos].preco) == 4) {
        printf("%d, %s, %d, %.2f\n", produto[*num_produtos].codigo, produto[*num_produtos].produto, produto[*num_produtos].quantidade, produto[*num_produtos].preco);
        (*num_produtos)++;
    }

    fclose(estoque);
    menu();
}

