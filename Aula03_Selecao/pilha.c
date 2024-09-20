#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no NO;
typedef struct jogador{
    char nome[50];
    int pontuacao;
} JOGADOR;

struct no {
    JOGADOR dados;
    NO *anterior;
};

struct pilha {
    NO *topo;
    int tamanho;
};

PILHA* pilha_criar(){
    PILHA *pilha = (PILHA*) malloc(sizeof(PILHA));

    if(pilha != NULL){
        pilha->topo = NULL;
        pilha->tamanho = 0;
    }
    return pilha;
}

bool pilha_vazia(PILHA *pilha){
    if(pilha != NULL){
        return (pilha->tamanho) == 0 ? true : false;
    }
    return false;
}

bool pilha_cheia(PILHA *pilha){
    if(pilha != NULL){
        NO *novo = (NO*) malloc(sizeof(NO));
        if(novo != NULL){
            free(novo);
            return true;
        }
        return false;
    }
    return false;
}

int pilha_tamanho(PILHA *pilha){
    if(pilha != NULL){
        return pilha->tamanho;
    }
    return -1;
}

JOGADOR pilha_topo(PILHA *pilha){
    if(pilha != NULL && !pilha_vazia(pilha)){
        return pilha->topo->dados;
    }

    exit(1);
}

void pilha_apagar(PILHA **pilha){
    NO *paux;
    if ((*pilha) != NULL && !pilha_vazia(*pilha)) {
        while ((*pilha)->topo != NULL) {
            paux = (*pilha)->topo;
            (*pilha)->topo = (*pilha)->topo->anterior;
            free(&paux->dados);
            paux->anterior = NULL;
            free(paux); 
            paux = NULL;
        }
    }
    free(*pilha);
    *pilha = NULL;
}

bool pilha_empilhar(PILHA *pilha, JOGADOR dados){
    NO* pnovo = (NO*) malloc(sizeof(NO));
    if(pnovo != NULL){
        pnovo->dados = dados;
        pnovo->anterior = pilha->topo;
        pilha->topo = pnovo;
        pilha->tamanho++;
        return true;
    }
    return false;
}

JOGADOR pilha_desempilhar(PILHA *pilha){
    if(pilha != NULL  && !(pilha_vazia(pilha))){
        NO* pno = pilha->topo;
        JOGADOR dados = pilha->topo->dados;
        pilha->topo = pilha->topo->anterior;
        pno->anterior = NULL;
        free(pno);
        pno = NULL;
        pilha->tamanho--;
        return dados;
    }

    exit(1);
}