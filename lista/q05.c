#include <stdio.h>

#define TAM1 5
#define TAM2 5

int jaExiste(int vetor[], int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) return 1;
    }
    return 0;
}

int main() {
    int v1[TAM1], v2[TAM2], comuns[TAM1 < TAM2 ? TAM1 : TAM2];
    int i, j, qtdComuns = 0;

    // Leitura do primeiro vetor
    printf("Digite %d números para o primeiro vetor:\n", TAM1);
    for (i = 0; i < TAM1; i++) {
        scanf("%d", &v1[i]);
    }

    // Leitura do segundo vetor
    printf("Digite %d números para o segundo vetor:\n", TAM2);
    for (i = 0; i < TAM2; i++) {
        scanf("%d", &v2[i]);
    }

    // Verifica elementos comuns
    for (i = 0; i < TAM1; i++) {
        for (j = 0; j < TAM2; j++) {
            if (v1[i] == v2[j] && !jaExiste(comuns, qtdComuns, v1[i])) {
                comuns[qtdComuns++] = v1[i];
                break;
            }
        }
    }

    // Exibe os elementos comuns
    if (qtdComuns == 0) {
        printf("Nenhum elemento comum encontrado.\n");
    } else {
        printf("Elementos comuns:\n");
        for (i = 0; i < qtdComuns; i++) {
            printf("%d ", comuns[i]);
        }
        printf("\n");
    }

    return 0;
}
