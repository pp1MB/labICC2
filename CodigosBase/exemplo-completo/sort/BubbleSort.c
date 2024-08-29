#include "BubbleSort.h"

//
void bubbleSort(int *vetor, int vectorSize)
{
    int aux;
    for(int i = 0; i < vectorSize; ++i)
	{
        for(int j = 0; j < vectorSize-i-1; ++j)
        {
            if(vetor[j] > vetor[j+1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
	}
}
