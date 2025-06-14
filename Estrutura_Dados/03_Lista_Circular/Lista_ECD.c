#include <stdio.h>
#include <stdlib.h>

struct no{          
    struct no* ant;
    int dado;
    struct no* prox;
};

struct lista{
    struct no *inicio;
    struct no *fim;
};

void inicia_lista(struct lista* lcd){    
    lcd->inicio = NULL;
    lcd->fim = NULL;
}

int lista_vazia(struct lista* lcd) {
    if (lcd->inicio == NULL){
        puts("Vazia");
        return 1;
    }
    return 0;
}

int lista_unitaria(struct lista* lcd){
    if(!lista_vazia(lcd) && lcd->inicio->prox == NULL){
        puts("Unitaria");
        return 1;
    }
    return 0;
}

void insere_lista(struct lista* lcd, int num) {
    struct no* novo = (struct no*) malloc(sizeof(struct no));

    if(novo){
        novo->dado = num;

        if(lista_vazia(lcd)){
            lcd->inicio = novo;
            lcd->fim = novo;
            puts("Valor inserido");
        }else{
            lcd->fim->prox = novo;
            novo->ant = lcd->fim;
            lcd->fim = novo;
            puts("Valor inserido");
        }

        lcd->fim->prox = lcd->inicio;
        lcd->inicio->ant = lcd->fim;
    }else{
        puts("Nao foi possivel inserir o valor");
    }
}

void remove_lista(struct lista* lcd, int num) {
    struct no* aux = lcd->inicio;
    struct no* anterior = NULL;

    if(!lista_vazia(lcd)){
        if(!lista_unitaria(lcd)){
            if(aux->dado == num){
                lcd->inicio = aux->prox;
                lcd->fim->prox = aux->prox;
                free(aux);
                puts("Valor removido");
            }else{
                while (aux->prox != lcd->inicio){
                    anterior = aux;
                    aux = aux->prox;

                    if (aux->dado == num){
                        anterior->prox = aux->prox;
                        aux->prox->ant = anterior;
                        free(aux);
                        puts("Valor removido");
                        break;
                    }
                }
            }
        }else{
            if(lcd->inicio->dado == num){
                lcd->inicio = NULL;
                lcd->fim = NULL;
                free(aux);
                puts("Valor removido");
            }
        }
    }else{
        puts("Nao foi possivel remover o valor");
    }
}

void mostra(struct lista* lcd) {
    struct no* aux = lcd->inicio;

    if(!lista_vazia(lcd)) {
        do{
            printf("%d\n", aux->dado);
            aux = aux->prox;
        }while (aux != lcd->inicio);
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
    struct lista lcd;
    inicia_lista(&lcd);

    while (1){
        int dado, opcao = menu();

        if (opcao == 1){
            printf("Digite o elemento a ser inserido: ");
            scanf("%d", &dado);
            insere_lista(&lcd, dado);
        }else if (opcao == 2){
            printf("Digite o elemento a ser removido: ");
            scanf("%d", &dado);
            remove_lista(&lcd, dado);
        }else if (opcao == 3){
            mostra(&lcd);
        }else if (opcao == 0){
            break;
        }else{
            puts("Opcao invalida");
        }
    }
}