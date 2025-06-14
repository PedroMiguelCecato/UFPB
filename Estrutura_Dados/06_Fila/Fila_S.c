#include <stdio.h>
#include <stdlib.h>

struct no{
    int dado;
    struct no* prox;
};

struct fila{
    struct no* inicio;
};

void inicia_fila(struct fila* F){
    F->inicio = NULL;
}

int fila_vazia(struct fila* F){
    if(F->inicio = NULL){
        puts("Fila vazia.\n");
        return 1;
    }
    return 0;
}

int fila_unitaria(struct fila* F){
    if(!fila_vazia(F)){
        if(F->inicio->prox = NULL){
            puts("Fila unitaria.\n");
            return 1;
        }
        return 0;
    }
    return 0;
}

void inserir_fila(struct fila* F, int num){
    struct no* novo = (struct no*) malloc(sizeof(struct no));
    struct no* aux = F->inicio;

    if(!novo){
        return;
    }
    novo->prox = NULL;
    novo->dado = num;
    
    if(!fila_vazia(F)){
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }else{
        F->inicio = novo;
    }
}

void remover_fila(struct fila* F){
    struct no* aux = F->inicio;

    if(!fila_vazia(F)){
        if(!fila_unitaria(F)){
            F->inicio = aux->prox;
            free(aux);
        }else{
            F->inicio = NULL;
            free(aux);
        }
    }
}

void mostra_fila(struct fila* F){
    if(!fila_vazia(F)){
        printf("%d.\n", F->inicio);
    }
}

int menu(){
    int opcao;

    printf("\nMenu:\n");
    printf("1. Insere na fila\n");
    printf("2. Remove da fila\n");
    printf("3. Mostra próximo valor da fila\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

int main(){
    struct fila f;
    inicia_fila(&f);

    while (1){
        int dado, opcao = menu();

        if (opcao == 1){
            printf("Digite o elemento a ser inserido: ");
            scanf("%d", &dado);
            inserir_fila(&f, dado);
        }else if (opcao == 2){
            remover_fila(&f);
        }else if (opcao == 3){
            mostra_fila(&f);
        }else if (opcao == 0){
            break;
        }else{
            puts("Opcao invalida");
        }
    }
}