#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include "atualizar_vendas.h"
#include "menu.h"
#include "structs.h"

void atualizar_vendas(struct produtos produto[], int *num_produtos, FILE *arquivo_vendas) {

    arquivo_vendas = fopen("vendas.csv", "a");
    FILE* estoque = fopen("estoque.csv", "r");
    
    if (arquivo_vendas == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    if (estoque == NULL) { //Verifica se o arquivo foi aberto com sucesso
        printf ("Erro ao abrir o arquivo\n");
        return;
    }

    char linha[100];
    while (fgets(linha, 100, estoque)) {
        sscanf (linha, "%d,%[^,],%d,%f", &produto[*num_produtos].codigo, produto[*num_produtos].produto, &produto[*num_produtos].quantidade, &produto[*num_produtos].preco); //Usando o sscanf pra ler os valores da string linha
        (*num_produtos)++;
    }

    int opcao3, opcao4 = 0, codigoprodvendido, quantvendida, indice_produto = -1;
    char produtovendido[MAX_PRODUTOSVENDIDOS];
    char data[MAX_DATA];

    printf("1 - Atualizar por codigo de produto\n");
    printf("2 - Atualizar por nome de produto\n");

    scanf("%d", &opcao3);

    switch (opcao3) {
        case 1:
            printf("Digite o codigo do produto vendido: ");
            scanf("%d", &codigoprodvendido);

            for (int i = 0; i < *num_produtos; i++) {
                if (produto[i].codigo == codigoprodvendido) {
                    indice_produto = i;
                    break;
                }
            }

            if (indice_produto == -1) {
                printf("Produto nao encontrado!\n");
                menu();
            }

            printf("Digite a quantidade vendida: ");
            scanf("%d", &quantvendida);

            if (quantvendida <= 0) {
                printf("Quantidade invalida!\n");
                return;
            }

            if (quantvendida > produto[indice_produto].quantidade) {
                printf("Quantidade em estoque insuficiente!\n");
                return;
            }

            produto[indice_produto].quantidade -= quantvendida;

            printf("Digite a data da venda (Data no formato DD/MM/AAAA): ");
            scanf("%s", data);

            // Grava a venda no arquivo de vendas.csv
            fprintf(arquivo_vendas, "%d,%s,%d,%s\n", codigoprodvendido, produto[indice_produto].produto, quantvendida, data);

            printf("Venda registrada com sucesso!\n");
            printf("Clique 1 para voltar para o menu ou 0 para sair do programa: ");
            scanf("%d", &opcao4);

            if (opcao4 == 1) {
                menu();
            } else {
                return;
            }

            fclose(arquivo_vendas);

            break;

        case 2:
            printf("Digite o nome do produto: ");
            getchar(); // Limpa o buffer do teclado antes de usar fgets
            fgets(produtovendido, MAX_PRODUTOSVENDIDOS, stdin);
            produtovendido[strcspn(produtovendido, "\n")] = '\0'; // Remove o caractere '\n' do final da string

            // Busca pelo produto com o nome fornecido
            indice_produto = -1;
            for (int i = 0; i < *num_produtos; i++) {
                if (strcmp(produto[i].produto, produtovendido) == 0) {
                    indice_produto = i;
                    break;
                }
            }

            if (indice_produto == -1) {
                printf("Produto nao encontrado.\n");
                menu();
            }

            printf("Digite a quantidade vendida: ");
            scanf("%d", &quantvendida);

            if (quantvendida <= 0) {
                printf("Quantidade invalida!\n");
                return;
            }

            if (quantvendida > produto[indice_produto].quantidade) {
                printf("Quantidade em estoque insuficiente!\n");
                return;
            }

            produto[indice_produto].quantidade -= quantvendida;

            printf("Digite da data da venda (Data no formato DD/MM/AAAA): ");
            getchar();
            fgets(data, MAX_DATA, stdin);

            // Escreve a venda no arquivo de vendas
            fprintf(arquivo_vendas, "%d,%s,%d,%s\n", codigoprodvendido, produtovendido, quantvendida, data);

            printf("Venda registrada com sucesso!\n");
            printf("Clique 1 para voltar para o menu ou 0 para sair do programa: ");

            scanf("%d", &opcao4);

            if (opcao4 == 1) {
                menu();
            } else {
                return;
            }

            fclose(arquivo_vendas);

            break;
        default:
            printf ("Comando invalido!");
            break;
    }

    fclose(arquivo_vendas);
    fclose(estoque);

    menu();
}
