#include <stdio.h>
#include <stdlib.h>

// Estrutura da Lista Duplamente Encadeada
struct no{          
    struct no* ant;
    int dado;
    struct no* prox;
};

// Estrutura que aponta para o início e fim da LDE
struct ld{      
    struct no* li;
    struct no* lf;
};

// Inicia LDE apontando início e fim para NULL
void inicia_lista(struct ld* lista){    
    lista->li = NULL;
    lista->lf = NULL;
}

// Verifica se está vazia e retorna 1 (vazia) ou 0 (não vazia)
int ld_vazia(struct ld* lista){     
    if(lista->li == NULL){
        puts("Eh vazia");
        return 1;
    }else{
        puts("Nao eh vazia");
        return 0;
    }
}

// Verifica se possui um elemento e retorna 1 (unitária) ou 0 (não unitária)
int ld_unitario(struct ld* lista){  
    if(lista->li == lista->lf && (!ld_vazia(lista))){   
        puts("Eh unitaria");
        return 1;    
    }else{
        puts("Nao eh unitaria");
        return 0;
    }
}

// Insere no início da LDE 
void inserir_inicio(struct ld* lista, int num){  
    struct no* novo;
   
    novo = (struct no*) malloc(sizeof(struct no));
    if(novo){
        novo->dado = num;
        novo->ant = NULL;
        novo->prox = lista->li;
       
        if(ld_vazia(lista)){
            lista->lf = novo;
        }else{
            novo->prox->ant = novo;
            //lista.li->ant = novo;      Tem a mesma função da linha acima
        }
        lista->li = novo;
        puts("Valor inserido no inicio");
    }else{
        puts("Valor nao foi inserido");
    }
}

// Insere no fim da LDE 
void inserir_fim(struct ld* lista, int num){ 
    struct no* novo;
   
    novo = (struct no*) malloc(sizeof(struct no));
    if(novo){
        novo->dado = num;
        novo->prox = NULL;
        novo->ant = lista->lf;
       
        if(ld_vazia(lista)){
            lista->li = novo;
        }else{
            novo->ant->prox = novo;
            //lista.lf->prox = novo;      Tem a mesma função da linha acima
        }
        lista->lf = novo;
        puts("Valor inserido no fim");
    }else{
        puts("Valor nao foi inserido");
    }
}

// Insere numa posição da LDE 
void inserir_meio(struct ld* lista, int num, int posicao){
    int cont = 0;
    struct no* novo = (struct no*) malloc(sizeof(struct no));
   
    if(ld_vazia(lista)){    // Caso a lista seja vazia
        inserir_inicio(lista, num);
        free(novo);
    }else if(ld_unitario(lista)){   // Caso a lista seja unitária
        inserir_fim(lista, num);
        free(novo);
    }else{          // Caso a lista tenha mais de um elemento
        struct no* aux = lista->li;
        struct no* ant = NULL;

        while(posicao){     // Chega na posição desejada
            if(aux->prox == NULL && posicao > 1){  // Se o valor de 'prox' for 'NULL', inserimos no fim
                inserir_fim(lista, num);
                free(novo);
            }

            ant = aux;
            aux = aux->prox;
            cont += 1;
            posicao -= 1;
        }
        
        ant->prox = novo;
        novo->prox = aux;
        novo->ant = ant;
        aux->ant = novo;
        puts("Valor inserido na posicao desejada");
    }
}

// Remove valor do início
void remover_inicio(struct ld* lista) {
    struct no* aux = lista->li;

    if(!ld_vazia(lista)){
        lista->li = lista->li->prox;
        lista->li->ant = NULL;
        free(aux);
        puts("Removido valor no inicio");
    }else{
        puts("Não foi possivel remover");
    }
}

// Remove valor do fim
void remover_fim(struct ld* lista) {
    struct no* aux = lista->li;
    struct no* anterior = NULL;

    if(!ld_vazia(lista)){
        if(!ld_unitario(lista)){
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
        puts("Não foi possivel remover");
    }
}

// Remove valor no meio
void remover_meio(struct ld* lista, int posicao){
    struct no* aux = lista->li;
    struct no* anterior = NULL;

    if (!ld_vazia(lista)){
        if(posicao == 0){
            remover_inicio(lista);
        }else{
            for (int i = 0; i < posicao; i++) {
                anterior = aux;
                aux = aux->prox;
            }

            anterior->prox = aux->prox;
            aux->prox->ant = anterior;
            free(aux);
            puts("Valor removido na posicao");
        }
    }else{
        puts("Não foi possivel remover");
    }
}

// Limpa a lista
void limpar_lista(struct ld* lista) {
    struct no* aux = lista->li;
    struct no* anterior = NULL;

    if(!ld_vazia(lista)){
        while(aux->prox != NULL) {
            anterior = aux;
            aux = aux->prox;
            free(anterior);
        }

        lista->li = NULL;
        lista->lf = NULL;
        free(aux);
    }
}

// Mostra a lista
void mostrar(struct ld* lista) {
    struct no* aux = lista->li;

    if (ld_vazia(lista)) {
        return;
    }
    while(aux != NULL) {
        printf("%d\n", aux->dado);
        aux = aux->prox;
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
    struct ld lista;
    inicia_lista(&lista);

    while(1){
        int rtrn, escolha = menu();

        if (escolha == 1){
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &rtrn);
            inserir_fim(&lista, rtrn);

        }else if (escolha == 2){
            remover_fim(&lista);

        }else if (escolha == 3){
            printf("Digite a posicao do valor a ser removido: ");
            scanf("%d", &rtrn);
            remover_meio(&lista, rtrn);

        }else if (escolha == 4){
            limpar_lista(&lista);

        }else if (escolha == 5){
            mostrar(&lista);

        }else if (escolha == 6){
            break;

        }else{
            puts("Opção inválida");
        }
    };

    limpar_lista(&lista);
    return 0;
}