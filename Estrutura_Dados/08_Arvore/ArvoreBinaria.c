#include <stdio.h>
#include <stdlib.h>

// Definindo estruturas
typedef struct no{
    int dado;
    struct no* esq;
    struct no* dir;
}No;

typedef struct ArvoreBinaria{
    No* raiz;
}ArvB;

// Funções primordiais
void inicia_arvore(ArvB* A){
    A->raiz = NULL;
}

int arvore_vazia(ArvB* A){
    if(A->raiz == NULL){
        puts("Arvore vazia.");
        return 1;
    }
    return 0;
}

int conta_no(No* raiz){
    int a, b;
    if(raiz){
        a = conta_no(raiz->esq);
        b = conta_no(raiz->dir);
        return a + b + 1;
    }
    return 0;
}

int altura_arvore(No* raiz){
    if(raiz){
        int a = altura_arvore(raiz->esq);
        int b = altura_arvore(raiz->dir);

        if(a>b){
            return a+1;
        }
        return b+1;
    }
    return 0;
}

// Funções para mostrar
void mostra_arvore_prefixada(struct no* raiz){
    if(raiz){
        printf("%d\n", raiz->dado);
        mostra_arvore(raiz->esq);
        mostra_arvore(raiz->dir);
    }
}

void mostra_arvore_infixada(struct no* raiz){ // Ordenado
    if(raiz){
        mostra_arvore_ordenado(raiz->esq);
        printf("%d\n", raiz->dado);
        mostra_arvore_ordenado(raiz->dir);
    }
}

void mostra_arvore_posfixada(struct no* raiz){
    if(raiz){
        mostra_arvore_ordenado(raiz->esq);
        mostra_arvore_ordenado(raiz->dir);
        printf("%d\n", raiz->dado);
    }
}

// Função auxiliar para criar o nó
struct no* cria_ramificacao(int num, struct no* esq, struct no* dir){
    struct no* novo = (struct no*) malloc(sizeof(struct no));

    if(!novo){
        return 0;
    }

    novo->dado = num;
    novo->esq = esq;
    novo->dir = dir;
    return novo;
}

// Funções de balanceamento
int FatorB(struct no* raiz){
    return altura_arvore(raiz->esq) - altura_arvore(raiz->dir);
}

void RotacaoRR(struct no* raiz){
    struct no* aux = raiz->dir;
    raiz->dir = aux->esq;
    aux->esq = raiz;
    raiz = aux;
}

void RotacaoLL(struct no* raiz){
    struct no* aux = raiz->esq;
    raiz->esq = aux->dir;
    aux->dir = raiz;
    raiz = aux;
}

void RotacaoRL(struct no* raiz){
    RotacaoLL(raiz->dir);
    RotacaoRR(raiz);
}

void RotacaoLR(struct no* raiz){
    RotacaoRR(raiz->esq);
    RotacaoLL(raiz);
}

void Balanceamento(struct no* raiz){
    if(FatorB(raiz) > 1){
        if(FatorB(raiz->esq) >= 0){ // Caso LL (rotação direita)
            RotacaoLL(raiz);
        }else{ // Caso LR (rotação esquerda-direita)
            RotacaoLR(raiz);
        }
    }else if(FatorB(raiz) < -1){ // Caso RR (rotação esquerda)
        if(FatorB(raiz->dir) <= 0){
            RotacaoRR(raiz);
        }else{ // Caso RL (rotação direita-esquerda)
            RotacaoRL(raiz);
        }
    }
}

// Inserir na árvore (sem repetição)
void inserir_esquerda(struct no* raiz, int valor){
    if(raiz->esq == NULL){
        raiz->esq = cria_ramificacao(valor, 0, 0);
    }else{
        if(valor < raiz->esq->dado){
            inserir_esquerda(raiz->esq, valor);
        }
        if(valor > raiz->esq->dado){
            inserir_direita(raiz->esq, valor);
        }
    }
}

void inserir_direita(struct no* raiz, int valor){
    if(raiz->dir == NULL){
        raiz->dir = cria_ramificacao(valor, 0, 0);
    }else{
        if(valor < raiz->dir->dado){
            inserir_esquerda(raiz->dir, valor);
        }
        if(valor > raiz->dir->dado){
            inserir_direita(raiz->dir, valor);
        }
    }
}

void inserir_arvore(ArvB* A, int valor){
    if(!arvore_vazia(A)){
        if(valor < A->raiz->dado){
            inserir_esquerda(A->raiz, valor);
        }
        if(valor > A->raiz->dado){
            inserir_direita(A->raiz, valor);
        }
    }else{
        A->raiz = cria_ramificacao(valor, 0, 0);
    }
    Balanceamento(A->raiz);
}

// Remover árvore
struct no* limpa_arvore(struct no* raiz){
    if(raiz){
        raiz->esq = limpa_arvore(raiz->esq);
        raiz->dir = limpa_arvore(raiz->dir);
        free(raiz);
        return 0;
    }
    return 0;
}

struct no* remove_no(struct no* raiz, int valor){
    if(raiz == NULL){
        printf("Valor não encontrado.\n");
        return NULL;
    }else{
        if(raiz->dado == valor){
            if(raiz->esq == NULL && raiz->dir == NULL){
                free(raiz);
                return NULL;
            }else{
                if(raiz->esq == NULL && raiz->dir == NULL){
                    struct no* aux = raiz->esq;

                    while(raiz->dir != NULL){
                        aux = aux->dir;
                    }
                    raiz->dado = aux->dado;
                    aux->dado = valor;
                    raiz->esq = remove_no(raiz->esq, valor);
                    return raiz;
                }else{
                    struct no* aux;

                    if(raiz->esq != NULL){
                        aux = raiz->esq;
                    }else{
                        aux = raiz->dir;
                    }
                    free(raiz);
                    return aux;
                }
            }
        }else{
            if(valor < raiz->dado){
                raiz->esq = remover_no(raiz->esq, valor);
            }else{
                raiz->dir = remover_no(raiz->dir, valor);
            }
            return raiz;
        }
    }
}

// Menu
int menu(){
    int opcao;

    printf("\nMenu:\n");
    printf("1. Inserir elemento\n");
    printf("2. Mostrar arvore (ordenada)\n");
    printf("3. Limpar arvore\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

int main(){
    struct ArvoreBinaria* A;
    inicia_arvore(A);

    while (1){
        int dado, opcao = menu();

        if (opcao == 1){
            printf("Digite o elemento a ser inserido: ");
            scanf("%d", &dado);
            inserir_arvore(A->raiz, dado);
        }else if (opcao == 2){
            mostra_arvore_infixada(A->raiz);
        }else if (opcao == 3){
            limpa_arvore(A->raiz);
        }else if (opcao == 0){
            break;
        }else{
            puts("Opcao invalida");
        }
    }
}