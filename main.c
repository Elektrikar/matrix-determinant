#include <stdio.h>

void print_matrix(int n, double matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5lf ", matrix[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

int abs(int x) {
    return x > 0 ? x : -x;
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return abs((a / gcd(a, b)) * b);
}

void swap_rows(int n, double matrix[n][n], int idx1, int idx2) {
    for (int i = 0; i < n; i++) {
        int tmp = matrix[idx1][i];
        matrix[idx1][i] = matrix[idx2][i];
        matrix[idx2][i] = tmp;
    }
}

int det(int n, double matrix[n][n]) {
    int result = 1;
    int swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        if (matrix[i][i] == 0) {
            for (int j = i + 1; j < n; j++) {
                if (matrix[j][i] != 0) {
                    swap_rows(n, matrix, i, j);
                    swaps++;
                    break;
                }

                if (j == n - 1)
                    return 0;
            }
        }
        
        for (int j = i + 1; j < n; j++) {
            if (matrix[j][i] == 0)
                continue;

            int curr_lcm = lcm(matrix[i][i], matrix[j][i]);
            double mult_i = curr_lcm / matrix[i][i];
            double mult_j = curr_lcm / matrix[j][i];

            for (int k = 0; k < n; k++) {
                matrix[j][k] = (matrix[j][k] * mult_j - matrix[i][k] * mult_i) / mult_j;
            }
        }

        result *= matrix[i][i];
    }

    result *= matrix[n - 1][n - 1];
    return swaps % 2 ? -result : result;
}

int main () {
    int n;
    scanf("%d", &n);

    double matrix[n][n];
    for (int i = 0; i < n * n; i++) {
        scanf("%lf", &matrix[i / n][i % n]);
    }

    printf("\n|A| = %d\n\n", det(n, matrix));
    print_matrix(n, matrix);

    return 0;
}