#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include "editar_produto.h"
#include "menu.h"
#include "structs.h"

void editar_produto (struct produtos produto[], int *num_produtos) {
    FILE *estoque = fopen("estoque.csv", "w"); // Abre o arquivo para escrita

    if (estoque == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    int opcao, codigo;
    char nome[MAX_PRODUTOS];
    printf("1 - Editar por codigo de produto\n");
    printf("2 - Editar por nome de produto\n");
    printf("0 - Voltar\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:

            printf("Digite o codigo do produto a ser editado: ");
            scanf("%d", &codigo);

            char linha[100];
            int encontrado = 0;

            // Lê cada linha do arquivo CSV e verifica se o código corresponde ao código pesquisado
            while (fgets(linha, sizeof(linha), estoque)) {
                struct produtos produto;
                sscanf(linha, "%d,%[^,],%d,%f", &produto.codigo, produto.produto, &produto.quantidade, &produto.preco);

                if (produto.codigo == codigo) {
                    printf("Produto encontrado! Produto: %d, %s, %d, %.2f\n", produto.codigo, produto.produto, produto.quantidade, produto.preco);
                    encontrado = 1;
                    break;
                }
            }

            if (encontrado == 0) { // Se o produto não foi encontrado, exibe a mensagem de erro
                printf("Codigo nao encontrado\n");
            }

            // Pede novos dados para o produto
            printf("Digite o novo codigo do produto: ");
            scanf("%d", produto->codigo);
            printf("Digite o novo nome do produto: ");
            fgets(produto->produto, MAX_PRODUTOS, stdin);
            printf("Digite a nova quantidade do produto: ");
            scanf("%d", &produto->quantidade);
            printf("Digite o novo preco do produto: ");
            scanf("%f", &produto->preco);

            // Grava os produtos no arquivo
            for (int i = 0; i < *num_produtos; i++) {
                fprintf(estoque, "%d, %s, %d, %.2f\n", produto[i].codigo, produto[i].produto, produto[i].quantidade, produto[i].preco);
            }

            printf("Produto editado com sucesso!\n");
            fclose(estoque); // Fecha o arquivo antes de retornar
            break;

        case 2:

            printf("Digite o nome do produto a ser editado: ");
            fgets(nome, 100, stdin);
            nome[strcspn(nome, "\n")] = '\0';

            // Busca pelo produto com o nome fornecido
            int indice_produto = -1;
            for (int i = 0; i < *num_produtos; i++) {
                if (strcmp(produto[i].produto, nome) == 0) {
                    indice_produto = i;
                    break;
                } else {
                    printf("Produto nao encontrado!\n");
                    return;
                }
            }

            // Mostra os dados do produto
            printf("Codigo: %d\n", produto[indice_produto].codigo);
            printf("Produto: %s\n", produto[indice_produto].produto);
            printf("Quantidade: %d\n", produto[indice_produto].quantidade);
            printf("Preco: %.2f\n", produto[indice_produto].preco);

            // Pede novos dados para o produto
            printf("Digite o novo codigo do produto: ");
            scanf("%d", produto[indice_produto].codigo);
            printf("Digite o novo nome do produto: ");
            fgets(produto[indice_produto].produto, MAX_PRODUTOS, stdin);
            printf("Digite a nova quantidade do produto: ");
            scanf("%d", &produto[indice_produto].quantidade);
            printf("Digite o novo preco do produto: ");
            scanf("%f", &produto[indice_produto].preco);

            // Grava os produtos no arquivo
            for (int i = 0; i < *num_produtos; i++) {
                fprintf(estoque, "%d, %s, %d, %.2f\n", produto[i].codigo, produto[i].produto, produto[i].quantidade, produto[i].preco);
            }

            printf("Produto editado com sucesso!\n");
            fclose(estoque); // Fecha o arquivo antes de retornar
            break;

        case 0:
            menu();
            break;
        default:
            printf ("Comando invalido.\n");
            break;
    }

    menu ();
}
