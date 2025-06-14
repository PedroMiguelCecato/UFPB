#include <stdio.h>
#include <stdlib.h>

// Estrutura da Lista Simplismente Encadeada
struct no{          
    int dado;
    struct no* prox;
};

// Estrutura que aponta para o início e fim da LSE
struct ls{      
    struct no* li;
};

// Inicia LSE apontando início e fim para NULL
void inicia_lista(struct ls* lista){    
    lista->li = NULL;
}

// Verifica se está vazia e retorna 1 (vazia) ou 0 (não vazia)
int ls_vazia(struct ls* lista){     
    if(lista->li == NULL){
        puts("Eh vazia");
        return 1;
    }else{
        puts("Nao eh vazia");
        return 0;
    }
}

// Verifica se possui um elemento e retorna 1 (unitária) ou 0 (não unitária)
int ls_unitario(struct ls* lista){  
    if(lista->li != NULL && lista->li->prox == NULL){
        puts("Eh unitaria");
        return 1;    
    }else{
        ls_vazia(lista);
        puts("Nao eh unitaria");
        return 0;
    }
}

// Insere no início da LSE
void inserir_inicio(struct ls* lista, int num){  
    struct no* novo = (struct no*) malloc(sizeof(struct no));
   
    if(novo){
        novo->dado = num;
        novo->prox = lista->li;
        lista->li = novo;
        puts("Valor inserido no inicio");
    }else{
        puts("Valor nao foi inserido");
    }
}

// Insere no fim da LSE
void inserir_fim(struct ls* lista, int num){ 
    struct no* novo = (struct no*) malloc(sizeof(struct no));
    struct no* aux = lista->li;
   
    if(novo){
        novo->dado = num;
        novo->prox = NULL;
       
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
        puts("Valor inserido no fim");
    }else{
        puts("Valor nao foi inserido");
    }
}

// Insere numa posição da LDE
void inserir_meio(struct ls* lista, int num, int posicao){
    struct no* novo = (struct no*) malloc(sizeof(struct no));
   
    if(ls_vazia(lista)){    // Caso a lista seja vazia
        inserir_inicio(lista, num);
        free(novo);
    }else if(ls_unitario(lista)){   // Caso a lista seja unitária
        (posicao == 1) ? inserir_fim(lista, num) : inserir_inicio(lista, num);
        free(novo);
    }else{          // Caso a lista tenha mais de um elemento
        struct no* aux = lista->li;
        struct no* anterior = NULL;
        int cont_passos = 0;

        while(posicao > -1){     // Chega na posição desejada
            anterior = aux;
            aux = aux->prox;
            cont_passos += 1;
            posicao -= 1;
        }
        
        anterior->prox = novo;
        novo->prox = aux;
        puts("Valor inserido na posicao desejada");
    }
}

// Remove valor do início
void remover_inicio(struct ls* lista) {
    struct no* aux = lista->li;

    if(!ls_vazia(lista)){
        lista->li = lista->li->prox;
        free(aux);
        puts("Removido valor no inicio");
    }else{
        puts("Nao foi possivel remover");
    }
}

// Remove valor do fim
void remover_fim(struct ls* lista) {
    struct no* aux = lista->li;
    struct no* anterior = NULL;

    if(!ls_vazia(lista)){
        if(!ls_unitario(lista)){
            while(aux->prox != NULL) {
                anterior = aux;
                aux = aux->prox;
            }
            anterior->prox = NULL;
            free(aux);
            puts("Removido valor no fim");
        }else{
            remover_inicio(lista);
        }
    }else{
        puts("Nao foi possivel remover");
    }    
}

// Remove valor no meio
void remover_meio(struct ls* lista, int posicao){
    struct no* aux = lista->li;
    struct no* ant = NULL;

    if(!ls_vazia(lista)){
        if(posicao == 0){
            remover_inicio(lista);
        }else{
            for (int i = 0; i < posicao; i++) {
                ant = aux;
                aux = aux->prox;
            }

            ant->prox = aux->prox;
            free(aux);
            puts("Valor removido na posicao");
        }
    }else{
        puts("Nao foi possivel remover");
    } 
}

// Limpa a lista
void limpar_lista(struct ls* lista) {
    struct no* aux = lista->li;
    struct no* anterior = NULL;

    if(!ls_vazia(lista)){
        while(aux->prox != NULL) {
            anterior = aux;
            aux = aux->prox;
            free(anterior);
        }
        lista->li = NULL;
        free(aux);
    }
}

// Mostra a lista
void mostrar(struct ls* lista) {
    struct no* aux = lista->li;

    if(!ls_vazia(lista)) {
        while(aux->prox != NULL) {
            printf("%d\n", aux->dado);
            aux = aux->prox;
        }
        printf("%d\n", aux->dado);
    }
}

// Menu
int menu(){
    int escolha;

    printf("\nMenu:\n");
    printf("1. Inserir valor no fim da lista\n");
    printf("2. Remover valor do fim da lista\n");
    printf("3. Remover valor da posicao X\n");
    printf("4. Limpar lista\n");
    printf("5. Mostrar lista\n");
    printf("6. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);
    return escolha;
}

int main(){
    struct ls lista;
    inicia_lista(&lista);

    while(1){
        int rtrn, escolha = menu();

        if(escolha == 1){
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &rtrn);
            inserir_fim(&lista, rtrn); 
        }else if(escolha == 2){
            remover_fim(&lista);
        }else if(escolha == 3){
            printf("Digite a posicao do valor a ser removido: ");
            scanf("%d", &rtrn);
            remover_meio(&lista, rtrn);
        }else if(escolha == 4){
            limpar_lista(&lista);
        }else if(escolha == 5){
            mostrar(&lista);
        }else if(escolha == 6){
            break;
        }else{
            puts("Opção inválida");
        }
    };
    
    limpar_lista(&lista);
    return 0;
}