#include <stdio.h>
#define TAM_LIST 10

struct list{
    int vetor[TAM_LIST];
    int controle;
};

void cria_lista(struct list* lv){
    lv->controle = -1;
}

int lista_vazia(struct list* lv){
    if(lv->controle == -1){
        puts("Lista esta vazia.");
        return 1;
    }
    return 0;
}

int lista_unitaria(struct list* lv){
    if(lv->controle == 0){
        puts("A lista eh unitaria.");
        return 1;
    }
    return 0;
}

int lista_cheia(struct list* lv) {
    if (lv->controle == TAM_LIST - 1){
        puts("Lista esta cheia.");
        return 1;
    }
    return 0;
}

void insere_ordenado(struct list* lv, int dado) {
    if(!lista_cheia(lv)){
        lv->controle++;
        lv->vetor[lv->controle] = dado;
        printf("Elemento inserido com sucesso!\n");
    }else{
        puts("Não foi possível inserir o valor.");
    }
}