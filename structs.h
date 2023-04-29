#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

// Definicao das constantes
#define MAX_PRODUTOS 100
#define MAX_PRODUTOSVENDIDOS 100
#define MAX_DATA 11

// Definicao das estruturas
struct produtos {
    int codigo;
    char produto[MAX_PRODUTOS];
    float preco;
    int quantidade;
};

struct vendas {
    int codigo;
    int quantidadevendida;
    char produtovendido[MAX_PRODUTOSVENDIDOS];
    char data[MAX_DATA]; //Data no formato DD/MM/AAAA
};


#endif // STRUCTS_H_INCLUDED
