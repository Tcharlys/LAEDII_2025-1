#include <stdio.h>

int inverteNumero(int n) {
    int invertido = 0;
    int sinal = (n < 0) ? -1 : 1;
    n *= sinal;  // torna o número positivo temporariamente

    while (n > 0) {
        invertido = invertido * 10 + n % 10;
        n /= 10;
    }

    return invertido * sinal;  // aplica o sinal original
}

int main() {
    int numero;

    printf("Digite um número: ");
    scanf("%d", &numero);

    int resultado = inverteNumero(numero);
    printf("Número invertido: %d\n", resultado);

    return 0;
}