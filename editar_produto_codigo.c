#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include "editar_produto.h"
#include "menu.h"
#include "structs.h"

void editar_produto_codigo (struct produtos produto[], int *num_produtos) {
    FILE *estoque = fopen("estoque.csv", "r+"); // Abre o arquivo para escrita

    if (estoque == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    int codigo;

        printf("Digite o codigo do produto a ser editado: ");
        scanf("%d", &codigo);

        char linha[100];
        int encontrado = 0;

        // Lê cada linha do arquivo CSV e verifica se o código corresponde ao código pesquisado
        long int posicao_atual = ftell(estoque); // armazena a posição atual do ponteiro do arquivo
        while (fgets(linha, sizeof(linha), estoque)) {
            struct produtos linha_produto;
            sscanf(linha, "%d,%[^,],%d,%f", &linha_produto.codigo, linha_produto.produto, &linha_produto.quantidade, &linha_produto.preco);

            if (linha_produto.codigo == codigo) {
                printf("Produto encontrado! Produto: %d, %s, %d, %.2f\n", linha_produto.codigo, linha_produto.produto, linha_produto.quantidade, linha_produto.preco);
                encontrado = 1;

                // Atualiza as informações do produto
                printf("Digite o novo codigo do produto: ");
                scanf("%d", &linha_produto.codigo);
                printf("Digite o novo nome do produto: ");
                scanf ("%s", linha_produto.produto);
                printf("Digite a nova quantidade do produto: ");
                scanf("%d", &linha_produto.quantidade);
                printf("Digite o novo preco do produto: ");
                scanf("%f", &linha_produto.preco);

                // Posiciona o ponteiro do arquivo na linha do produto atualizado
                fseek(estoque, posicao_atual, SEEK_SET);

                // Escreve as informações atualizadas do produto no arquivo
                fprintf(estoque, "%d,%s,%d,%.2f\n", linha_produto.codigo, linha_produto.produto, linha_produto.quantidade, linha_produto.preco);

                printf("Produto editado com sucesso!\n");
                }
            posicao_atual = ftell(estoque); // atualiza a posição atual do ponteiro do arquivo
        }

        if (encontrado == 0) { // Se o produto não foi encontrado, exibe a mensagem de erro
            printf("Codigo nao encontrado\n");
        }

        fclose(estoque); // Fecha o arquivo antes de retornar   

    menu ();
}
