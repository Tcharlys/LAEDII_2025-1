#include <stdio.h>
#include <time.h>

#define MAX 1000
int memo[MAX];

int x_optimized(int n) {
    if (memo[n] != -1) return memo[n];
    if (n <= 1) return memo[n] = 1;
    return memo[n] = x_optimized(n - 1) + x_optimized(n - 2);
}

int main() {
    int n = 45;
    int NMax = 1000;
    double total_time = 0.0;

    for (int i = 0; i < NMax; i++) {
        for (int j = 0; j <= n; j++) memo[j] = -1;

        clock_t start = clock();
        x_optimized(n);
        clock_t end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("Tempo médio (otimizado): %f segundos\n", total_time / NMax);
    return 0;
}
