#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define FILENAME "numeros"
#define BINARYEXTENSION ".bin"
#define TEXTEXTENSION ".txt"

typedef struct numeros_t {
    int *numeros;
    int tamanho;
} numeros_t;

// Estrutura para armazenar o tempo de execução
typedef struct {
    clock_t start;
    clock_t end;
} Timer;

// Inicializa o timer
void start_timer(Timer *timer) {
    timer->start = clock();
}

// Para o timer e calcula o tempo decorrido
double stop_timer(Timer *timer) {
    timer->end = clock();
    return ((double) (timer->end - timer->start)) / CLOCKS_PER_SEC;
}


int obterNumeroDigitos(int numero){
    if(numero == 0){
        return 1;
    }

    int digitos = 0;
    while(numero > 0){
        numero = numero/10;
        digitos++;
    }
    return digitos;
}

char* criarNomeArquivo(int tamanho, char *extensao){
    char *filename, *nomeLista;

    // obter número de dígitos do tamanho
    int numeroDigitos = obterNumeroDigitos(tamanho);
    int filenameSize = strlen(FILENAME) + numeroDigitos + strlen(extensao) + 1;
    nomeLista = (char *) malloc(numeroDigitos * sizeof(char));
    sprintf(nomeLista, "%d", tamanho);

    filename = (char *) malloc(filenameSize * sizeof(char));

    strcpy(filename, FILENAME);
    strcat(filename, nomeLista);
    strcat(filename, extensao);
    
    return filename;
}

int escreverListaEmArquivoBinario(numeros_t lista){
    FILE *arquivo;

    char* filename = criarNomeArquivo(lista.tamanho, BINARYEXTENSION);

    arquivo = fopen(filename, "wb");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        return -1;
    }

    fwrite(lista.numeros, sizeof(int), lista.tamanho, arquivo);
    fclose(arquivo);
    return 1;
}

int escreverListaEmArquivoTexto(numeros_t lista){
    FILE *arquivo;

    char* filename = criarNomeArquivo(lista.tamanho, TEXTEXTENSION);

    arquivo = fopen(filename, "wb");

    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        return -1;
    }

    for(int i=0; i < lista.tamanho; i++){
        fprintf(arquivo, "%d\n", lista.numeros[i]);
    }
    fclose(arquivo);
    return 1;
}

void imprimeTempoExecucao(double tempo){
    printf("Tempo de execução: %f segundos\n", tempo);
}

int main(){
    numeros_t lista;
    Timer timer;

    printf("Digite o numero de elementos: ");
    scanf("%d", &lista.tamanho);

    srand(time(NULL));

    lista.numeros = (int *) malloc(lista.tamanho * sizeof(int));

    start_timer(&timer);
    for(int i = 0; i < lista.tamanho; i++){
        lista.numeros[i] = rand();
    }
    imprimeTempoExecucao(stop_timer(&timer));

    start_timer(&timer);
    escreverListaEmArquivoBinario(lista);
    imprimeTempoExecucao(stop_timer(&timer));

    start_timer(&timer);
    escreverListaEmArquivoTexto(lista);
    imprimeTempoExecucao(stop_timer(&timer));

    free(lista.numeros);

    return 0;
}