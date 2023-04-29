#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <ctype.h>
#include "atualizar_produtos.h"
#include "listar_produtos.h"
#include "adicionar_produto.h"
#include "remover_produto.h"
#include "editar_produto.h"
#include "pesquisar_produto.h"
#include "atualizar_vendas.h"
#include "gerar_relatorio_vendas.h"
#include "criar_arquivo.h"
#include "menu.h"
#include "structs.h"

void menu() {

    struct produtos produto[MAX_PRODUTOS]; // Criacao do array de produtos
    struct vendas produtovendido[MAX_PRODUTOSVENDIDOS]; // Criacao do array de vendas
    int num_produtos = 0;

    int opcao = -1, opcaopesquisa2, opcaoed;

    do {

        printf ("Escolha uma das opcoes abaixo: \n");
        printf ("1 - Lista de produtos\n");
        printf ("2 - Adicionar produtos\n");
        printf ("3 - Remover produtos\n");
        printf ("4 - Editar produtos\n");
        printf ("5 - Pesquisar produtos\n");
        printf ("6 - Atualizar vendas\n");
        printf ("7 - Gerar relatorio de vendas\n");
        printf ("0 - Sair\n");

        scanf ("%d", &opcao);
        getchar();

        switch (opcao)
        {
            case 1:
                listar_produtos(produto, &num_produtos); // Chama a funcao que lista os produtos
                break;
            case 2:
                adicionar_produto(produto, &num_produtos); // Chama a funcao para adicionar produto
                break;
            case 3:
                remover_produto(produto, &num_produtos);
                break;
            case 4:
                printf("1 - Editar por codigo de produto\n");
                printf("2 - Editar por nome de produto\n");
                scanf("%d", &opcaoed);
                switch (opcaoed)
                {
                    case 1:
                        editar_produto_codigo(produto, &num_produtos);
                        break;
                    case 2:
                        editar_produto_nome(produto, &num_produtos);
                        break;
                    default:
                        printf ("Opcao invalida. Fim do programa!\n");
                        return; // Encerra o programa
                }
                break;
            case 5:
                printf ("Pesquisar produtos por: \n");
                printf ("1 - Codigo: \n");
                printf ("2 - Nome\n");
                scanf ("%d", &opcaopesquisa2);
                switch (opcaopesquisa2)
                {
                    case 1:
                        pesquisar_produto_codigo (produto, &num_produtos);
                        break;
                    case 2:
                        pesquisar_produto_nome (produto, &num_produtos);
                        break;
                    default:
                        printf ("Opcao invalida. Fim do programa!\n");
                        return; // Encerra o programa
                }
                break;
                case 6:
                    atualizar_vendas(produto, &num_produtos, fopen("nome_arquivo_vendas.csv","r"));
                    break;
                case 7:
                    gerar_relatorio_vendas("nome_arquivo_vendas.csv", produto, &num_produtos);
                    break;
                case 0:
                    printf ("Fim do programa. Obrigada por usar o nosso sistema!");
                    break;
                default:
                    printf ("Opcao invalida! Fim do programa!");
            }
    atualizar_produtos(produto, &num_produtos); // Atualiza o array de produtos
    } while (opcao != 0);
}
