#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include "gerar_relatorio_vendas.h"
#include "menu.h"
#include "structs.h"

void gerar_relatorio_vendas(char *nome_arquivo_vendas, struct produtos produto[], int *num_produtos) {

    FILE *arquivo_vendas = fopen("vendas.csv", "r");

    if (arquivo_vendas == NULL) {
        printf("Erro ao abrir o arquivo de vendas\n");
        return;
    }

    struct vendas venda;
    int codigo_produto, quantidade_vendida;
    float valor_total_vendas = 0;

    printf("Relatorio de Vendas\n");
    printf("Produto\t\t\tQuantidade\tVendas\t\tTotal Arrecadado\n");

    for (int i = 0; i < *num_produtos; i++) {
        codigo_produto = produto[i].codigo;
        quantidade_vendida = 0;
        float valor_total_produto = 0;

        rewind(arquivo_vendas);
        while (fscanf(arquivo_vendas, "%d,%[^,],%d,%d", &venda.codigo, venda.produtovendido, &venda.quantidadevendida, &produto->preco) != EOF) {
            if (venda.codigo == codigo_produto) {
                quantidade_vendida += venda.quantidadevendida;
                valor_total_produto += produto[i].preco * venda.quantidadevendida;
                valor_total_vendas += produto[i].preco * venda.quantidadevendida;
            }
        }

        if (quantidade_vendida > 0) {
            printf("%s\t\t\t%d\t\t%d\t\t%.2f\n", produto[i].produto, quantidade_vendida, quantidade_vendida / produto[i].quantidade, valor_total_produto);
        }
    }

    printf("\nTotal de vendas: %.2f\n", valor_total_vendas);

    fclose(arquivo_vendas);
    menu();
}
