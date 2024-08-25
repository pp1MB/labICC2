#include "StopWatch.h"

void showTime(time_t time)
{

    double time_taken = ((double)time)/CLOCKS_PER_SEC; // in seconds

    printf("Tempo para executar tarefa: %.6f\n", time_taken);
}


time_t measureTime(time_t *time)
{
    if(time == NULL)
    {
        printf("Relogio iniciado\n");
        return clock();
    }
	//Soh atualiza o tempo atual 
	//e mostra a diferen�a entre a medida passada
    else
    {
        *time = clock() - *time;
        showTime(*time);
        return *time;
    }
}
