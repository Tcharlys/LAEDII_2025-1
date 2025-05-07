#include <stdio.h>

#define TAM 3

int main() {
    int A[TAM][TAM], B[TAM][TAM], C[TAM][TAM];

    // Leitura da matriz A
    printf("Digite os elementos da matriz A (3x3):\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // Leitura da matriz B
    printf("Digite os elementos da matriz B (3x3):\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    // Soma das matrizes A e B
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // Exibição do resultado
    printf("Matriz resultante da soma (C = A + B):\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}