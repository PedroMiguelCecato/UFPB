#include <stdio.h>
#include <stdlib.h>

struct no{          
    int dado;
    struct no* prox;
};

struct lista {
    struct no *inicio;
    struct no *fim;
};

void inicia_lista(struct lista* los){    
    los->inicio = NULL;
    los->fim = NULL;
}

int lista_vazia(struct lista* los) {
    if (los->inicio == NULL){
        puts("Vazia");
        return 1;
    }
    return 0;
}

int lista_unitaria(struct lista* los){
    if(!lista_vazia(los) && los->inicio->prox == NULL){
        puts("Unitaria");
        return 1;
    }
    return 0;
}

void inserir_ordenado(struct lista* los, int num) {
    struct no* novo = (struct no*) malloc(sizeof(struct no));

    novo->dado = num;
    novo->prox = NULL;
    if (!lista_vazia(los)){
        struct no* aux = los->inicio;
        struct no* ant = NULL;

        if (aux->dado > novo->dado){
            novo->prox = aux;
            los->inicio = novo;
        }else{
            while (ant->prox != NULL && novo->dado > aux->dado){
                ant = aux;
                aux = aux->prox;
            }
            ant->prox = novo;
            novo->prox = aux;
        }
        
        if(novo->prox == NULL){
            los->fim = novo;
        }
    }else{
        los->inicio = novo;
        los->fim = novo;
        novo->prox = NULL;
    }
}

void remover_inicio(struct lista* los){
    struct no* aux = los->inicio;

    if(!lista_vazia(los)){
        los->inicio = los->inicio->prox;
        free(aux);
    }
}

void remover_fim(struct lista* los){
    struct no* aux = los->inicio;
    struct no* ant = NULL;

    if(!lista_vazia(los)){
        while (aux->prox != NULL){
            ant = aux;
            aux = aux->prox;
        }
        los->fim = ant;
        free(aux);
        ant->prox = NULL;
    }
}

void mostrar(struct lista* los) {
    struct no* aux = los->inicio;

    if(!lista_vazia(los)) {
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
    struct lista los;
    inicia_lista(&los);

    while (1){
        int dado, opcao = menu();

        if (opcao == 1){
            printf("Digite o elemento a ser inserido: ");
            scanf("%d", &dado);
            insere_lista(&los, dado);
        }else if (opcao == 2){
            remover_inicio(&los);
        }else if (opcao == 3){
            remover_fim(&los);
        }else if (opcao == 4){
            mostrar(&los);
        }else if (opcao == 0){
            break;
        }else{
            puts("Opcao invalida");
        }
    }
}