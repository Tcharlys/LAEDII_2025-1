#include <stdio.h>

int main() {
    int matriz[4][4];  // Declaração da matriz 4x4
    int somaDiagonal = 0;

    // Leitura dos elementos da matriz
    printf("Digite os elementos da matriz 4x4:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Elemento[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Cálculo da soma da diagonal principal
    for (int i = 0; i < 4; i++) {
        somaDiagonal += matriz[i][i];  // Elementos da diagonal principal têm índices iguais
    }

    // Exibição da soma
    printf("A soma dos elementos da diagonal principal é: %d\n", somaDiagonal);

    return 0;
}