#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include "remover_produto.h"
#include "menu.h"
#include "structs.h"

void remover_produto (struct produtos produto[], int *num_produtos) {
    FILE *estoque = fopen ("estoque.csv", "r"); //Abrindo um arquivo para leitura

    if (estoque == NULL) { //Verifica se o arquivo foi aberto com sucesso
        printf ("Erro ao abrir o arquivo\n");
        return;
    }

    char linha[100];
    while (fgets(linha, 100, estoque)) {
        sscanf (linha, "%d,%[^,],%d,%f", &produto[*num_produtos].codigo, produto[*num_produtos].produto, &produto[*num_produtos].quantidade, &produto[*num_produtos].preco); //Usando o sscanf pra ler os valores da string linha
        (*num_produtos)++;
    }

    printf ("Digite código do produto a ser removido: "); //Pedindo pra saber qual o produto a ser removido
    int codigoremovido;
    scanf("%d", &codigoremovido);
    getchar(); //limpa o buffer do teclado

    int procura = -1; //Procurando o codigo do produto no array
    for (int i = 0; i < *num_produtos; i++) {
        if (produto[i].codigo == codigoremovido) {
            procura = i;
            break;
        } 
    }

    if (procura == -1) {
        printf ("Produto nao encontrado na base de dados.\n");
        return;
    }

    for (int i = procura; i < *num_produtos - 1; i++) { //Removendo o produto do array
        produto[i] = produto[i+1];
    }

    (*num_produtos)--;

    estoque = fopen ("estoque.csv", "w"); //Abrindo o arquivo para escrita
    if (estoque == NULL) { //Verifica se o arquivo foi aberto com sucesso
        printf ("Erro ao abrir o arquivo\n");
        return;
    }

    for (int i = 0; i < *num_produtos; i++) {
        fprintf (estoque, "%d,%s,%d,%.2f\n", produto[i].codigo, produto[i].produto, produto[i].quantidade, produto[i].preco);
    }

    fclose(estoque);

    menu();
}



