#ifndef PILHA_H
    #define PILHA_H
    #include <stdbool.h>
    typedef struct pilha PILHA;
    typedef struct jogador JOGADOR;
    #define TAM 100

    PILHA* pilha_criar();
    bool pilha_vazia(PILHA *pilha);
    bool pilha_cheia(PILHA *pilha);
    int pilha_tamanho(PILHA *pilha);
    JOGADOR pilha_topo(PILHA *pilha);
    void pilha_apagar(PILHA **pilha);
    bool pilha_empilhar(PILHA *pilha, JOGADOR dados);
    JOGADOR pilha_desempilhar(PILHA *pilha);
#endif