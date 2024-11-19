#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX 1000000


int superRand(int max){
    return rand() % max;
}

void generate_list(int *arr, int size) {
    bool *used = (bool *) calloc(sizeof(bool), MAX);
    for (int i = 0; i < size; i++) {
        int num;
        do {
            num = superRand(MAX);
        } while (used[num]);
        arr[i] = num;
        used[num] = 1;
    }

    free(used);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    if(argc > 2)
        return 1;

    int n = atoi(argv[1]);

    for (int i = 0; i < n; ++i) {
        char filename[50];
        sprintf(filename, "casos_teste/%d.in", i + 1);
        
        FILE *file = fopen(filename, "w");
        if (file == NULL) {
            perror("Failed to open file");
            return 1;
        }

        int m = 1000 + 1000 * i;

        int *vec = (int *) malloc(m * sizeof(int));
        generate_list(vec, m);

        fprintf(file, "%d\n", m);
        for (int j = 0; j < m; ++j) {
            fprintf(file, "%d ", vec[j]);
        }

        fclose(file);
    }
}