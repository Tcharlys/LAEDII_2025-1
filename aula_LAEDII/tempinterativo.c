#include <stdio.h>
#include <time.h>

int x_iterativo(int n) {
    if (n <= 1) return 1;

    int a = 1, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n = 100; // valor alto, possível com versão iterativa
    int NMax = 1000;
    double total_time = 0.0;

    for (int i = 0; i < NMax; i++) {
        clock_t start = clock();
        x_iterativo(n);
        clock_t end = clock();
        total_time += (double)(end - start) / CLOCKS_PER_SEC;
    }

    printf("Tempo médio (otimizado iterativo): %f segundos\n", total_time / NMax);
    return 0;
}
