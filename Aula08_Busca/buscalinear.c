#include <stdio.h>
#include <stdlib.h> 


int busca_linear(int *v, int n, int k){
    for(int i = 0;i < n; i++){
        if(v[i] == k){
            return i;
        }
    }
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int *v = (int *) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }

    int pos = busca_linear(v, n, k);

    printf("%d\n", pos + 1);
}

