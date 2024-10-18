#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CASOS 100

void generate_random_number_string(char *str, int length) {
    const char digits[] = "234567AJKQ";
    for (size_t i = 0; i < length - 1; ++i) {
        str[i] = digits[rand() % 10];
    }
    str[length - 1] = '\0';
}

char *generate_random_card_suit() {
    char *suits[] = {"♦", "♠", "♥", "♣"}; 

    char *selected_suit = suits[rand() % 4];
    return selected_suit;
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

        int num_strings = 10 + i * 3;
        int string_length = 5 + (i / 20);

        fprintf(file, "%d %d\n", num_strings, string_length - 1);
        for (int j = 0; j < num_strings; ++j) {
            char *str = (char *) malloc(string_length * sizeof(char));
            generate_random_number_string(str, string_length);
            fprintf(file, "%s %s\n", generate_random_card_suit(), str);
        }

        fclose(file);
    }
}