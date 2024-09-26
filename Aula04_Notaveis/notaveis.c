#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno_{
    char nome[50];
    float aumento;
} ALUNO;


int comparar(const void *a, const void *b) {
    ALUNO *alunoA = (ALUNO *)a;
    ALUNO *alunoB = (ALUNO *)b;
    if (alunoA->aumento < alunoB->aumento) return 1;
    else if(alunoA->aumento > alunoB->aumento) return -1;
    return strcmp(alunoA->nome, alunoB->nome);
}


ALUNO ler_linha(FILE *arq){
    ALUNO aluno;
    char c = fgetc(arq);

    int i = 0;
    while(1 == 1){
        if(c == ','){
            aluno.nome[i] = '\0';
            break;
        }

        aluno.nome[i] = c;
        i++;
        c = fgetc(arq);
    }

    float* notas = (float*) malloc(3*sizeof(float));
    fscanf(arq, "%f,%f,%f ", &notas[0], &notas[1], &notas[2]);

    //fgetc(arq);

    aluno.aumento = notas[2] - notas[0];

    free(notas);
    return aluno;
}

int main(){
    char nome_arquivo[50];
    int k;

    scanf("%s %d", nome_arquivo, &k);


    FILE *arq = fopen(nome_arquivo, "r");   
    if(arq == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    // Leitura da primeira linha do código que deve ser ignorada
    char c = fgetc(arq);
    while (c != '\n'){
        c = fgetc(arq);
    };

    // Leitura dos alunos, 50 é um numero arbritário para o tamanho inicial do vetor
    ALUNO *alunos = (ALUNO*) malloc(50*sizeof(ALUNO));
    int i = 0;
    while(!feof(arq)){
        if(i % 50 == 0 && i != 0){
            alunos = (ALUNO*) realloc(alunos, (i+50)*sizeof(ALUNO));
        }

        alunos[i] = ler_linha(arq);
        i++;
    }

    qsort(alunos, i, sizeof(ALUNO), comparar);

    // int j = 0;
    // for(; j < k; j++){
    //     printf("%s %f\n", alunos[j].nome, alunos[j].aumento);
    // }

    // while(j < i && alunos[j].aumento == alunos[j - 1].aumento){
    //     printf("%s %f\n", alunos[j].nome, alunos[j].aumento);
    //     j++;
    // }

    int j = 0;
    for(; j < k; j++){
        printf("%s\n", alunos[j].nome);
    }

    while(j < i && alunos[j].aumento == alunos[j - 1].aumento){
        printf("%s\n", alunos[j].nome);
        j++;
    }

    free(alunos);
    fclose(arq);
}   
