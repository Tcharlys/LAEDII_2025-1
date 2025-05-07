#include <stdio.h>

// Função de busca binária
int buscaBinaria(int vetor[], int tamanho, int chave) {
    int inicio = 0, fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vetor[meio] == chave) {
            return meio; // encontrado
        } else if (vetor[meio] < chave) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1; // não encontrado
}

int main() {
    int vetor[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int chave;

    printf("Digite o valor a ser buscado: ");
    scanf("%d", &chave);

    int posicao = buscaBinaria(vetor, tamanho, chave);

    if (posicao != -1) {
        printf("Valor %d encontrado na posição %d.\n", chave, posicao);
    } else {
        printf("Valor %d não encontrado no vetor.\n", chave);
    }

    return 0;
}