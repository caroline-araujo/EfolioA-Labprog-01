#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include "atualizar_produtos.h"
#include "listar_produtos.h"
#include "menu.h"
#include "structs.h"

void atualizar_produtos(struct produtos produto[], int *num_produtos) {
    FILE *estoque = fopen("estoque.csv", "r");

    if (estoque == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    // Limpa o conteudo do array de produtos
    *num_produtos = 0;
    memset(produto, 0, sizeof(struct produtos) * MAX_PRODUTOS);

    while (fscanf(estoque, "%d, %[^,], %d, %f\n", &produto[*num_produtos].codigo, produto[*num_produtos].produto, &produto[*num_produtos].quantidade, &produto[*num_produtos].preco) != EOF) {
        (*num_produtos)++;
    }

    fclose(estoque);
}
