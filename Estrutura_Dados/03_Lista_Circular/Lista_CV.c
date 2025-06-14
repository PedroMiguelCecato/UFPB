#include <stdio.h>
#define TAM_LIST 10

struct list{
    int vetor[TAM_LIST];
    int inicio;
    int fim;
};

void cria_lista(struct list* lcv){
    lcv->inicio = -1;
    lcv->fim = -1;
}

int lista_vazia(struct list* lcv){
    if(lcv->inicio == -1){
        puts("Lista esta vazia.");
        return 1;
    }
    return 0;
}

int lista_cheia(struct list* lcv) {
    if (lcv->inicio > 0){
        if(lcv->fim == lcv->inicio - 1){
            puts("Lista esta cheia.");
            return 1;
        }
        return 0;
    }else{
        if (lcv->fim == TAM_LIST - 1){
            puts("Lista esta cheia.");
            return 1;
        }
        return 0;
    }
}

int lista_unitaria(struct list* lcv){
    if(lcv->fim == lcv->inicio && lcv->inicio != -1){
        puts("A lista eh unitaria.");
        return 1;
    }
    return 0;
}

void insere_lista(struct list* lcv, int dado) {
    if(!lista_cheia(lcv)){
        if (lcv->inicio == 0){
            lcv->fim += 1;
            lcv->vetor[lcv->fim] = dado;
            puts("Elemento inserido com sucesso!");
        }else{
            if (lcv->fim == TAM_LIST -1){
                lcv = 0;
                lcv->vetor[lcv->fim] = dado;
                puts("Elemento inserido com sucesso!");
            }else{
                lcv->fim += 1;
                lcv->vetor[lcv->fim] = dado;
            }
        }
    }else{
        puts("Não foi possível inserir o valor.");
    }
}

void remove_lista(struct list* lcv, int valor){
    if(!lista_vazia(lcv)){
        if (lcv->inicio == 0){
            for (int i = 0; i <= lcv->fim; i++){
                if (lcv->vetor[i] == valor){
                    for (int j = i; j <= lcv->fim; j++){
                        lcv->vetor[j] = lcv->vetor[j + 1]; 
                    }
                    lcv->fim--;
                    puts("Elemento removido com sucesso!");
                    return;
                }
            }     
        }else{
            for (int i = lcv->inicio; i != lcv->fim; i++){
                if(i == TAM_LIST){
                    i = 0;
                }
                if (lcv->vetor[i] == valor){
                    for (int j = i; j != lcv->fim; j++){
                        if(j == TAM_LIST - 1){
                            lcv->vetor[j] = lcv->vetor[0];
                            j = -1;
                        }else{
                            lcv->vetor[j] = lcv->vetor[j + 1];
                        } 
                    }
                    lcv->fim--;
                    puts("Elemento removido com sucesso!");
                    return;
                }
            }
        }
    }else{
        puts("Não foi possível remover o valor.");
    }    
}

void mostra_lista(struct list* lcv){
    if (!lista_vazia(lcv)){
        if (lcv->inicio == 0){
            for (int i = 0; i <= lcv->fim; i++){
                printf("%d\n", lcv->vetor[i]);
            }
        }else{
            for (int i = lcv->inicio; i != lcv->fim; i++){
                if (i == TAM_LIST){
                    printf("%d\n", lcv->vetor[0]);
                    i = -1;
                }else{
                    printf("%d\n", lcv->vetor[i]);
                }
            }
        }
    }
}

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