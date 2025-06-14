#include <stdio.h>
#include <stdlib.h>

struct no{          
    struct no* ant;
    int dado;
    struct no* prox;
};

struct lista {
    struct no *inicio;
    struct no *fim;
};

void inicia_lista(struct lista* lod){    
    lod->inicio = NULL;
    lod->fim = NULL;
}

int lista_vazia(struct lista* lod) {
    if (lod->inicio == NULL){
        puts("Vazia");
        return 1;
    }
    return 0;
}

int lista_unitaria(struct lista* lod){
    if(!lista_vazia(lod) && lod->inicio->prox == NULL){
        puts("Unitaria");
        return 1;
    }
    return 0;
}

void inserir_ordenado(struct lista* lod, int num) {
    struct no* novo = (struct no*) malloc(sizeof(struct no));

    novo->dado = num;
    novo->ant = NULL;
    novo->prox = NULL;
    if (!lista_vazia(lod)){
        struct no* aux = lod->inicio;
        struct no* ant = NULL;

        if (aux->dado > novo->dado){
            novo->prox = aux;
            aux->ant = novo;
            lod->inicio = novo;
        }else{
            while (ant->prox != NULL && novo->dado > aux->dado){
                ant = aux;
                aux = aux->prox;
            }
            ant->prox = novo;
            novo->ant = ant;
            novo->prox = aux;

            if(aux != NULL){
                aux->ant = novo;
            }
        }
        
        if(novo->prox == NULL){
            lod->fim = novo;
        }
    }else{
        lod->inicio = novo;
        lod->fim = novo;
    }
}

void remover_inicio(struct lista* lod){
    struct no* aux = lod->inicio;

    if(!lista_vazia(lod)){
        lod->inicio = lod->inicio->prox;
        free(aux);
        lod->inicio->ant = NULL;
    }
}

void remover_fim(struct lista* lod){
    struct no* aux = lod->inicio;
    struct no* ant = NULL;

    if(!lista_vazia(lod)){
        while (aux->prox != NULL){
            ant = aux;
            aux = aux->prox;
        }
        lod->fim = ant;
        free(aux);
        ant->prox = NULL;
    }
}

void mostrar(struct lista* lod) {
    struct no* aux = lod->inicio;

    if(!lista_vazia(lod)) {
        while (aux != NULL) {
            printf("%d\n", aux->dado);
            aux = aux->prox;
        }
    }
}

int menu(){
    int opcao;

    printf("\nMenu:\n");
    printf("1. Inserir elemento\n");
    printf("2. Remover elemento início\n");
    printf("3. Remover elemento fim\n");
    printf("4. Imprimir lista\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

int main(){
    struct lista lod;
    inicia_lista(&lod);

    while (1){
        int dado, opcao = menu();

        if (opcao == 1){
            printf("Digite o elemento a ser inserido: ");
            scanf("%d", &dado);
            insere_lista(&lod, dado);
        }else if (opcao == 2){
            remover_inicio(&lod);
        }else if (opcao == 3){
            remover_fim(&lod);
        }else if (opcao == 4){
            mostrar(&lod);
        }else if (opcao == 0){
            break;
        }else{
            puts("Opcao invalida");
        }
    }
}