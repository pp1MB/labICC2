/* Grupo
 * Pedro Henrique de Sousa Prestes - 15507819
 * Pedro Lunkes Villela - 15484287 */

/* Trabalho 4 -Notaveis */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    clock_t start;
    clock_t end;
} Timer;


void start_timer(Timer *timer) {
    timer->start = clock();
}

double stop_timer(Timer *timer) {
    timer->end = clock();
    return ((double) (timer->end - timer->start)) / CLOCKS_PER_SEC;
}

/* Struct dos alunos a serem avaliados.*/
typedef struct aluno_{
    char nome[50];
    float aumento;
} ALUNO;

/* Protótipo das funções. */
int comparar(const void *a, const void *b);
ALUNO ler_linha(FILE *arq);

int main(){
    /* Leitura e abertura do arquivo. */
    char nome_arquivo[50];
    int k;

    scanf("%s %d", nome_arquivo, &k);

    Timer timer;
    start_timer(&timer);

    FILE *arq = fopen(nome_arquivo, "r");   
    if(arq == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    /* Leitura da primeira linha do código que deve ser ignorada */
    char c = fgetc(arq);
    while (c != '\n'){
        c = fgetc(arq);
    };

    /* Leitura dos alunos, 50 é um numero arbritário para o tamanho inicial do vetor.
     * Caso o tamanho seja maior que 50, realoca memória. */
    ALUNO *alunos = (ALUNO*) malloc(50 * sizeof(ALUNO));
    int i = 0;
    while(!feof(arq)){
        if(i % 50 == 0 && i != 0){
            alunos = (ALUNO*) realloc(alunos, (i + 50) * sizeof(ALUNO));
        }

        alunos[i] = ler_linha(arq);
        i++;
    }

    /* QuickSort. */
    qsort(alunos, i, sizeof(ALUNO), comparar);

    /* Printa os alunos ordenados pelo aumento. Até o valor k*/
    int j;
    for(j = 0; j < k; j++){
        printf("%s\n", alunos[j].nome);
    }

    /* Printa os alunos ordenados pelo aumento com o mesmo valor do último. */
    while(j < i && alunos[j].aumento == alunos[j - 1].aumento){
        printf("%s\n", alunos[j].nome);
        j++;
    }

    printf("Tempo de execução: %f segundos\n", stop_timer(&timer));

    free(alunos);
    fclose(arq);

    return 0;
}   

/* Função de comparação para uso no qsort().
 * Caso os alunos tenham o mesmo aumento, retorna a comparação lexicográfica. */
int comparar(const void *a, const void *b) {
    ALUNO *alunoA = (ALUNO *)a;
    ALUNO *alunoB = (ALUNO *)b;
    if (alunoA->aumento < alunoB->aumento) return 1;
    else if(alunoA->aumento > alunoB->aumento) return -1;
    return strcmp(alunoA->nome, alunoB->nome);
}

/* Lê as informações aluno presente no arquivo (arq). */
ALUNO ler_linha(FILE *arq){
    ALUNO aluno;
    char c = fgetc(arq);

    /* Lê o nome do aluno, adicionando o término da string.*/
    int i = 0;
    while(c != ','){
        aluno.nome[i] = c;
        i++;
        c = fgetc(arq);
    }
    aluno.nome[i] = '\0';

    /* Lê as notas dos alunos.*/
    float* notas = (float *) malloc(3 * sizeof(float));
    fscanf(arq, "%f,%f,%f ", &notas[0], &notas[1], &notas[2]);

    /* Pega a última nota e a primeira para cálculo do aumento.*/
    aluno.aumento = notas[2] - notas[0];

    free(notas);
    notas = NULL;

    return aluno;
}
