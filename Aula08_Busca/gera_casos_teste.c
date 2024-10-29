#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000000


int superRand(int max){
    return rand() % max;
}

int generate_ordered_list(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = superRand(MAX);
    }

    return arr[superRand(size)];
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

        int m = 10000 + 10000 * i;

        int *vec = (int *) malloc(m * sizeof(int));
        int target = generate_ordered_list(vec, m);

        fprintf(file, "%d %d\n", m, target);
        for (int j = 0; j < m; ++j) {
            fprintf(file, "%d ", vec[j]);
        }

        fclose(file);
    }
}