#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *file = fopen("input.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int n = 100;

    fprintf(file, "%d\n", n);

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Generate random numbers between -10 and 10
            int random_val = (rand() % 21) - 10;
            fprintf(file, "%d ", random_val);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Successfully generated %d numbers in 'input.txt'\n", n * n);

    return 0;
}