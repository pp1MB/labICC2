#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "NumberList.h"
#include "StopWatch.h"
#include "FileManager.h"
#include "QuickSort.h"
#include "BubbleSort.h"


int main(){

	//Um vetor pra cada algoritmo pra ficar mais fácil
    numberList_t vetorQuick, vetorBubble;
	
    char fileName[30];
    int i;
    clock_t executionTime;

    scanf("%s", fileName);
	
	//Lê o vetor e só copia pro resto
    vetorQuick = readNumberBinaryFile(fileName);
    vetorBubble = vetorQuick;
    vetorBubble.numbers = (int*) malloc(sizeof(int)*vetorBubble.listSize);
    for(int i = 0; i < vetorBubble.listSize; ++i)
    {
        vetorBubble.numbers[i] = vetorQuick.numbers[i];
    }

    printf("Vetor desordenado:\n");
    for(i = 0; i < vetorQuick.listSize; i++){
      printf("%d ", vetorQuick.numbers[i]);
    }
    printf("\n");

	//Executa cada ordenacao, mede o tempo e mostra a saida
	
    executionTime = measureTime(NULL);

    Quick(vetorQuick.numbers, 0, vetorQuick.listSize-1);
	
	printf("\nTempo Quick Sort\n");
    measureTime(&executionTime);

    printf("Vetor ordenado Quicksort:\n");
    for(i = 0; i < vetorQuick.listSize; i++){
      printf("%d ", vetorQuick.numbers[i]);
    }
    printf("\n");

    measureTime(&executionTime);

    bubbleSort(vetorBubble.numbers, vetorBubble.listSize);

	printf("\nTempo Bubble Sort\n");

    measureTime(&executionTime);

    printf("Vetor ordenado BubbleSort:\n");
    for(i = 0; i < vetorBubble.listSize; i++){
      printf("%d ", vetorBubble.numbers[i]);
    }
    printf("\n");

    measureTime(&executionTime);

    printf("\n");


}
