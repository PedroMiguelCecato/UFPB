#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct calculadora{
    int vetor[20];
    int controle;
};

void iniciar_calculadora(struct calculadora* c){
    c->controle = -1;
}

void push(struct calculadora* c){
    int opc;

    printf("Digite (1 - valor, 2 - operacao): ");
    scanf("%d", &opc);

}