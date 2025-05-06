#include <stdio.h>

int main() {
    int numeros[10];
    int contagem[10] = {0};
    int i, j;
    int jaContado;

    // Leitura dos 10 números
    printf("Digite 10 números inteiros:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &numeros[i]);
    }

    // Contagem de ocorrências
    for (i = 0; i < 10; i++) {
        jaContado = 0;

        // Verifica se o número já foi contado anteriormente
        for (j = 0; j < i; j++) {
            if (numeros[i] == numeros[j]) {
                jaContado = 1;
                break;
            }
        }

        // Se não foi contado, conta quantas vezes aparece
        if (!jaContado) {
            int count = 1;
            for (j = i + 1; j < 10; j++) {
                if (numeros[i] == numeros[j]) {
                    count++;
                }
            }
            printf("O número %d aparece %d vez(es).\n", numeros[i], count);
        }
    }

    return 0;
}
