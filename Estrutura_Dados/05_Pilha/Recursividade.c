#include <stdio.h>

// Retorna o fatorial do valor inserido, usando recusão
int fatorial(int n){
    if(n == 1){
        return 1;
    }
    return n * fatorial(n-1);
}

// Retorna o valor inteiro na posição de fibonacci desejada, usando recusão
int fibonacci(int n){
    if(n == 1 || n == 2){
        return 1;
    }else if(n > 2){
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
    return 0;
}

int fibonacci2(int n){
    if(n == 1 || n == 2){
        return 1;
    }else if(n > 2){
        int a = fibonacci2(n - 1);
        int b = fibonacci2(n - 2);
        return a+b;
    }
    return 0;
}

int main(){
    int valor;

    scantf("%d", &valor);
    printf("Fatorial: %d\nFibonacci: %d\n", fatorial(valor), fibonacci(valor));
    
    return 0;
}