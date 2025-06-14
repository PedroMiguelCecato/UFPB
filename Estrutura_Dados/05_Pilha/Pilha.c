#include <stdio.h>
#include <stdlib.h>

struct no{
    int dado;
    struct no* prox;
};

struct pilha{
    struct no* topo;
};

void inicia_pilha(struct pilha* P){
    P->topo = NULL;
}

int pilha_vazia(struct pilha* P){
    if(P->topo == NULL){
        puts("Pilha vazia.\n");
        return 1;
    }
    return 0;
}

void push(struct pilha* P, int num){
    struct no* novo = (struct no*) malloc(sizeof(struct no));
   
    if(!novo){
        return;
    }
    novo->dado = num;
    
    if(!pilha_vazia(P)){
        novo->prox = P->topo;
        P->topo = novo;
    }else{
        novo->prox = NULL;
        P->topo = novo;
    }
}

void pop(struct pilha* P){
    struct no* aux = P->topo;
   
    if(!pilha_vazia(P)){
        P->topo = aux->prox;
        free(aux);
    }
}

void peek(struct pilha* P){
    if(!pilha_vazia(P)){
        printf("%d\n", P->topo->dado);
    }
}

int menu(){
    int opcao;

    printf("\nMenu:\n");
    printf("1. Push elemento\n");
    printf("2. Pop elemento\n");
    printf("3. Peek elemento\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

int main(){
    struct pilha p;
    inicia_pilha(&p);

    while (1){
        int dado, opcao = menu();

        if (opcao == 1){
            printf("Digite o elemento a ser inserido: ");
            scanf("%d", &dado);
            push(&p, dado);
        }else if (opcao == 2){
            pop(&p);
        }else if (opcao == 3){
            peek(&p);
        }else if (opcao == 0){
            break;
        }else{
            puts("Opcao invalida");
        }
    }
}