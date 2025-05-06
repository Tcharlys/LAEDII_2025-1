#include <stdio.h>

typedef struct {
    int valor;
    int frequencia;
} Numero;

int main() {
    int entrada[10];
    Numero contagem[10];
    int usados = 0;

    // Leitura dos 10 números
    printf("Digite 10 números inteiros:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &entrada[i]);
    }

    // Processa os números
    for (int i = 0; i < 10; i++) {
        int encontrado = 0;

        // Verifica se o número já foi registrado
        for (int j = 0; j < usados; j++) {
            if (contagem[j].valor == entrada[i]) {
                contagem[j].frequencia++;
                encontrado = 1;
                break;
            }
        }

        // Se não foi encontrado, adiciona à lista
        if (!encontrado) {
            contagem[usados].valor = entrada[i];
            contagem[usados].frequencia = 1;
            usados++;
        }
    }

    // Exibe os resultados
    for (int i = 0; i < usados; i++) {
        printf("O número %d aparece %d vez(es).\n", contagem[i].valor, contagem[i].frequencia);
    }

    return 0;
}
