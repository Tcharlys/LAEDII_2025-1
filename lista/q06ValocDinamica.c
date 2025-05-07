#include <stdio.h>
#include <stdlib.h>

int** alocaMatriz(int linhas, int colunas) {
    int** matriz = (int**)malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*)malloc(colunas * sizeof(int));
    }
    return matriz;
}

void liberaMatriz(int** matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void leMatriz(int** matriz, int linhas, int colunas, char nome) {
    printf("Digite os elementos da matriz %c (%dx%d):\n", nome, linhas, colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%c[%d][%d]: ", nome, i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void somaMatrizes(int** A, int** B, int** C, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void imprimeMatriz(int** matriz, int linhas, int colunas, char nome) {
    printf("Matriz %c (%dx%d):\n", nome, linhas, colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int linhas, colunas;

    printf("Informe o número de linhas: ");
    scanf("%d", &linhas);
    printf("Informe o número de colunas: ");
    scanf("%d", &colunas);

    // Aloca matrizes
    int** A = alocaMatriz(linhas, colunas);
    int** B = alocaMatriz(linhas, colunas);
    int** C = alocaMatriz(linhas, colunas);

    // Leitura e soma
    leMatriz(A, linhas, colunas, 'A');
    leMatriz(B, linhas, colunas, 'B');
    somaMatrizes(A, B, C, linhas, colunas);

    // Exibe resultados
    imprimeMatriz(C, linhas, colunas, 'C');

    // Libera memória
    liberaMatriz(A, linhas);
    liberaMatriz(B, linhas);
    liberaMatriz(C, linhas);

    return 0;
}
