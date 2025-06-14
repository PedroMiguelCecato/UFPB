#include <stdio.h>
#define TAM_LIST 10

// Estrutura da lista de vetor
struct list{
    int vetor[TAM_LIST];
    int controle;
};

// Função para criar a lista
void cria_lista(struct list* lv){
    lv->controle = -1;
}

// Função para verificar se é vazia 1 (true) 0 (false)
int lista_vazia(struct list* lv){
    if(lv->controle == -1){
        puts("Lista esta vazia.");
        return 1;
    }
    return 0;
}

// Função para verificar se está cheia 1 (true) 0 (false)
int lista_cheia(struct list* lv) {
    if (lv->controle == TAM_LIST - 1){
        puts("Lista esta cheia.");
        return 1;
    }
    return 0;
}

// Função para verificar se é unitária 1 (true) 0 (false)
int lista_unitaria(struct list* lv){
    if(lv->controle == 0){
        puts("A lista eh unitaria.");
        return 1;
    }
    return 0;
}

// Função para inserir na lista
void insere_lista(struct list* lv, int dado) {
    if(!lista_cheia(lv)){
        lv->controle++;
        lv->vetor[lv->controle] = dado;
        printf("Elemento inserido com sucesso!\n");
    }else{
        puts("Não foi possível inserir o valor.");
    }
}

// Função para remover da lista
void remove_lista(struct list* lv, int valor){
    if(!lista_vazia(lv)){
        for (int i = 0; i <= lv->controle; i++){
            if (lv->vetor[i] == valor && i != lv->controle){
                for (int j = i; j < lv->controle; j++){
                    lv->vetor[j] = lv->vetor[j + 1]; 
                }
                lv->controle--;
                printf("Elemento removido com sucesso!\n");
            }else if(lv->vetor[i] == valor){
                lv->vetor[lv->controle] = 0;
                lv->controle--;
                printf("Elemento removido com sucesso!\n");
            }
        }
    }else{
        puts("Não foi possível remover o valor.");
    }
}

// Função para mostrar a lista
void mostra_lista(struct list* lv){
    if (!lista_vazia(lv)){
        for (int i = 0; i <= lv->controle; i++){
            printf("%d\n", lv->vetor[i]);
        }
    }
}

// Função para menu
int menu(){
    int opcao;

    printf("Menu:\n");
    printf("0. Sair\n");
    printf("1. Inserir elemento\n");
    printf("2. Remover elemento\n");
    printf("3. Imprimir lista\n");
    printf("4. Verifica lista vazia\n");
    printf("5. Verifica lista cheia\n");
    printf("6. Verifica lista unitaria\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

int main(){
    struct list lista;
    cria_lista(&lista);

    while (1){
        int dado, opcao = menu();
        
        if (opcao == 0){
            printf("\nSaindo...\n");
            break;
        }else if (opcao == 1){
            printf("\nDigite o elemento a ser inserido: ");
            scanf("%d", &dado);
            insere_lista(&lista, dado);
        }else if (opcao == 2){
            printf("\nDigite o elemento a ser removido: ");
            scanf("%d", &dado);
            remove_lista(&lista, dado);
        }else if (opcao == 3){
            mostra_lista(&lista);
        }else if (opcao == 4){
            lista_vazia(&lista);
        }else if (opcao == 5){
            lista_cheia(&lista);
        }else if (opcao == 6){
            lista_unitaria(&lista);
        }else{
            printf("\nOpcao invalida!\n");
        }
    }
    return 0;
}