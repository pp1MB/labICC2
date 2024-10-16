#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_number_string(char *str, int length) {
    const char digits[] = "0123456789";
    for (size_t i = 0; i < length - 1; ++i) {
        str[i] = digits[rand() % 10];
    }
    str[length - 1] = '\0';
}

int main() {
    srand(time(NULL));
    size_t length = 10; 
    char random_number_string[length];
    
    generate_random_number_string(random_number_string, length);
    
    return 0;
}