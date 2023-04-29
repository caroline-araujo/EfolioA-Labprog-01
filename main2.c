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

int main () {

    setlocale(LC_ALL, "PORTUGUESE");
    char utilizador[100];

    printf ("====================SISTEMA DE GESTAO DE VENDAS====================\n\n");
    printf ("Insira seu nome: ");
    fgets (utilizador, 100, stdin);
    printf ("Seja bem-vindo, %s\n", utilizador);

    criar_arquivo();
    menu(); //Chama a funcao de menu

    return 0;
}








