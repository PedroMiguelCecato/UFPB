// Frequência de Números

#include <stdio.h>

int main() {
    int n, i, j;
    int x[2000] = {0};
    
    scanf("%d", &n);
    for(i=0; i < n; i++){
        scanf("%d", &j);
        x[j - 1] += 1;
    }
    
    for(i=0; i<2000; i++){
        if(x[i] != 0){
            printf("%d aparece %d vez(es)\n", i+1, x[i]);
        }
    }
    return 0;
}