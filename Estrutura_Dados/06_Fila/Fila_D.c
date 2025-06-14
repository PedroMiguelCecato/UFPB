#include <stdio.h>
#include <stdlib.h>

struct no{
    struct no* ant;
    int dado;
    struct no* prox;
};

struct fila{
    struct no* ext1;
    struct no* ext2;
};

void inicia_fila(struct fila* F){
    F->ext1 = NULL;
    F->ext2 = NULL;
}

int fila_vazia(struct fila* F){
    if(F->ext1 = NULL){
        puts("Fila vazia.\n");
        return 1;
    }
    return 0;
}

int fila_unitaria(struct fila* F){
    if(!fila_vazia(F)){
        if(F->ext1 == F->ext2){
            puts("Fila unitaria.\n");
            return 1;
        }
        return 0;
    }
    return 0;
}

void inserir_fila(struct fila* F, int num){
    struct no* novo = (struct no*) malloc(sizeof(struct no));
    struct no* ult = F->ext2;

    if(!novo){
        return;
    }
    novo->ant = NULL;
    novo->prox = NULL;
    novo->dado = num;
    
    if(!fila_vazia(F)){
        ult->prox = novo;
        novo->ant = ult;
        F->ext2 = novo;
    }else{
        F->ext1 = novo;
        F->ext2 = novo;
    }
}

void remover_fila(struct fila* F){
    struct no* prim = F->ext1;

    if(!fila_vazia(F)){
        if(!fila_unitaria(F)){
            F->ext1 = prim->prox;
            prim->prox->ant = NULL;
            free(prim);
        }else{
            F->ext1 = NULL;
            F->ext2 = NULL;
            free(prim);
        }
    }
}

void mostra_fila(struct fila* F){
    if(!fila_vazia(F)){
        printf("%d.\n", F->ext1);
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