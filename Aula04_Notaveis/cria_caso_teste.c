#include <stdio.h>
#include <stdlib.h>


char* cria_nome(){
    int tam = rand()%20 + 2;
    char *nome = (char*) malloc(tam*sizeof(char));
    
    for(int i = 0; i < tam; i++){
        nome[i] = 'a' + rand()%26;
    }
    nome[tam - 1] = '\0';
    return nome;
}

float cria_nota(){
    float a = rand()%101;
    return a / 10.0;
}

int main(){
    int n;
    scanf("%d", &n);

    FILE* arq = fopen("notas.csv", "w");

    for(int i = 0; i < n; i++){
        char* nome = cria_nome();
        float nota1 = cria_nota();
        float nota2 = cria_nota();
        float nota3 = cria_nota();

        fprintf(arq, "%s,%.2f,%.2f,%.2f\n", nome, nota1, nota2, nota3);
    }
}
