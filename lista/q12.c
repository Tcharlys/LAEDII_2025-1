#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para verificar se a string é um palíndromo
int isPalindrome(char str[]) {
    int inicio = 0;                // Inicia o ponteiro no começo da string
    int fim = strlen(str) - 1;     // Inicia o ponteiro no final da string

    // Loop até que o ponteiro de início ultrapasse o ponteiro de fim
    while (inicio < fim) {
        // Ignora caracteres não alfabéticos e transforma tudo em minúsculo
        if (!isalnum(str[inicio])) {
            inicio++;
        } else if (!isalnum(str[fim])) {
            fim--;
        } else {
            // Compara os caracteres de ambas as extremidades
            if (tolower(str[inicio]) != tolower(str[fim])) {
                return 0; // Se os caracteres não forem iguais, não é um palíndromo
            }
            inicio++;   // Move o ponteiro de início para frente
            fim--;      // Move o ponteiro de fim para trás
        }
    }
    return 1; // Se todos os caracteres corresponderem, é um palíndromo
}

int main() {
    char str[100];

    // Solicita a entrada da string
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    // Remove a nova linha (\n) caso tenha sido lida com o fgets
    str[strcspn(str, "\n")] = '\0';

    // Chama a função e verifica se a string é um palíndromo
    if (isPalindrome(str)) {
        printf("A string \"%s\" é um palíndromo.\n", str);
    } else {
        printf("A string \"%s\" não é um palíndromo.\n", str);
    }

    return 0;
}