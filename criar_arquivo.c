#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include "criar_arquivo.h"
#include "menu.h"
#include "structs.h"

void criar_arquivo() {
    FILE *estoque = fopen("estoque.csv", "a+");
    if (estoque == NULL) {
        printf("Erro ao criar o arquivo\n");
        return;
    }
    fclose(estoque);

    FILE *arquivo_vendas = fopen("vendas.csv", "a+");
    if (arquivo_vendas == NULL) {
        printf("Erro ao criar o arquivo\n");
        return;
    }
    fclose(arquivo_vendas);
}
