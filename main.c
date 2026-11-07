#include <stdio.h>

#define EPSILON 1e-9 // tolerance of floating-point comparisons

double fabs(double x) {
    return x < 0 ? -x : x;
}

void print_matrix(int n, double matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%9g ", matrix[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

void swap_rows(int n, double matrix[n][n], int idx1, int idx2) {
    for (int i = 0; i < n; i++) {
        double tmp = matrix[idx1][i];
        matrix[idx1][i] = matrix[idx2][i];
        matrix[idx2][i] = tmp;
    }
}

double det(int n, double matrix[n][n]) {
    double result = 1;
    int sign = 1;

    for (int i = 0; i < n - 1; i++) {
        if (fabs(matrix[i][i]) < EPSILON) {
            bool swapped = false;
            for (int j = i + 1; j < n; j++) {
                if (fabs(matrix[j][i]) > EPSILON) {
                    swap_rows(n, matrix, i, j);
                    sign = -sign;
                    swapped = true;
                    break;
                }
            }
            
            if (!swapped) return 0;
        }
        
        for (int j = i + 1; j < n; j++) {
            if (fabs(matrix[j][i]) < EPSILON) continue;

            double factor = matrix[j][i] / matrix[i][i];

            for (int k = i; k < n; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }

        result *= matrix[i][i];
    }

    result *= matrix[n - 1][n - 1];
    return sign * result;
}

int main () {
    int n;
    scanf("%d", &n);

    double matrix[n][n];
    for (int i = 0; i < n * n; i++) {
        scanf("%lf", &matrix[i / n][i % n]);
    }

    printf("\n|A| = %g\n\n", det(n, matrix));
    print_matrix(n, matrix);

    return 0;
}