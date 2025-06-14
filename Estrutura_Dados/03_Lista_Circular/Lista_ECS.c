#include <stdio.h>
#include <stdlib.h>

struct no {
    int dado;
    struct no *prox;
};

struct lista {
    struct no *inicio;
    struct no *fim;
};

void inicia_lista(struct lista* lcs){    
    lcs->inicio = NULL;
    lcs->fim = NULL;
}

int lista_vazia(struct lista* lcs) {
    if (lcs->inicio == NULL){
        puts("Vazia");
        return 1;
    }
    return 0;
}

int lista_unitaria(struct lista* lcs){
    if(!lista_vazia(lcs) && lcs->inicio->prox == NULL){
        puts("Unitaria");
        return 1;
    }
    return 0;
}

void insere_lista(struct lista* lcs, int num) {
    struct no* novo = (struct no*) malloc(sizeof(struct no));

    if(novo){
        novo->dado = num;
        novo->prox = NULL;

        if(lista_vazia(lcs)){
            lcs->inicio = novo;
            lcs->fim = novo;
            puts("Valor inserido");
        }else{
            lcs->fim->prox = novo;
            lcs->fim = novo;
            puts("Valor inserido");
        }
        lcs->fim->prox = lcs->inicio;
    }else{
        puts("Nao foi possivel inserir o valor");
    }
}

void remove_lista(struct lista* lcs, int num) {
    struct no* aux = lcs->inicio;
    struct no* anterior = NULL;

    if(!lista_vazia(lcs)){
        if(!lista_unitaria(lcs)){
            if(aux->dado == num){
                lcs->inicio = aux->prox;
                lcs->fim->prox = aux->prox;
                free(aux);
                puts("Valor removido");
            }else{
                while (aux->prox != lcs->inicio){
                    anterior = aux;
                    aux = aux->prox;

                    if (aux->dado == num){
                        anterior->prox = aux->prox;
                        free(aux);
                        puts("Valor removido");
                        break;
                    }
                }
            }
        }else{
            if(lcs->inicio->dado == num){
                lcs->inicio = NULL;
                lcs->fim = NULL;
                free(aux);
                puts("Valor removido");
            }
        }
    }else{
        puts("Nao foi possivel remover o valor");
    }
}

void mostra(struct lista* lcs) {
    struct no* aux = lcs->inicio;

    if(!lista_vazia(lcs)) {
        do{
            printf("%d\n", aux->dado);
            aux = aux->prox;
        }while (aux != lcs->inicio);
    }
}

int menu(){
    int opcao;

    printf("\nMenu:\n");
    printf("1. Inserir elemento\n");
    printf("2. Remover elemento\n");
    printf("3. Imprimir lista\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

int main() {
    struct lista lcs;
    inicia_lista(&lcs);

    while (1){
        int dado, opcao = menu();

        if (opcao == 1){
            printf("Digite o elemento a ser inserido: ");
            scanf("%d", &dado);
            insere_lista(&lcs, dado);
        }else if (opcao == 2){
            printf("Digite o elemento a ser removido: ");
            scanf("%d", &dado);
            remove_lista(&lcs, dado);
        }else if (opcao == 3){
            mostra(&lcs);
        }else if (opcao == 0){
            break;
        }else{
            puts("Opcao invalida");
        }
    }
}