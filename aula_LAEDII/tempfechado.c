#include <stdio.h>
#include <math.h>
#include <time.h>

// Calcula Fibonacci usando fórmula de Binet
long long fibonacci_binet(int n) {
    if (n <= 1) return n;
    
    double phi = (1.0 + sqrt(5.0)) / 2.0;
    return (long long)round(pow(phi, n) / sqrt(5.0));
}

int main() {
    int n = 50;                    // Número para calcular
    int testes = 1000;             // Quantas vezes medir
    
    clock_t inicio = clock();
    
    // Executa o cálculo várias vezes
    for (int i = 0; i < testes; i++) {
        fibonacci_binet(n);
    }
    
    clock_t fim = clock();
    double tempo_total = (double)(fim - inicio) / CLOCKS_PER_SEC;
    double tempo_medio = tempo_total / testes;
    
    // Mostra os resultados
    printf("Fibonacci(%d) = %lld\n", n, fibonacci_binet(n));
    printf("Tempo médio: %.6f segundos\n", tempo_medio);
    printf("Tempo total para %d execuções: %.6f segundos\n", testes, tempo_total);
    
    return 0;
}