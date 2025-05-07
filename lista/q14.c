#include <stdio.h>
#include <string.h>

// Função para criptografar a mensagem usando a Cifra de César
void cifraCesar(char *mensagem, int deslocamento) {
    for (int i = 0; i < strlen(mensagem); i++) {
        // Verifica se o caractere é uma letra maiúscula
        if (mensagem[i] >= 'A' && mensagem[i] <= 'Z') {
            mensagem[i] = ((mensagem[i] - 'A' + deslocamento) % 26) + 'A';
        }
        // Verifica se o caractere é uma letra minúscula
        else if (mensagem[i] >= 'a' && mensagem[i] <= 'z') {
            mensagem[i] = ((mensagem[i] - 'a' + deslocamento) % 26) + 'a';
        }
    }
}

int main() {
    char mensagem[100];
    int deslocamento;

    // Solicita a mensagem a ser criptografada
    printf("Digite a mensagem para criptografar: ");
    fgets(mensagem, sizeof(mensagem), stdin);

    // Remove o caractere de nova linha '\n' da entrada
    mensagem[strcspn(mensagem, "\n")] = '\0';

    // Solicita o valor do deslocamento
    printf("Digite o deslocamento (número de posições): ");
    scanf("%d", &deslocamento);

    // Criptografa a mensagem
    cifraCesar(mensagem, deslocamento);

    // Exibe a mensagem criptografada
    printf("Mensagem criptografada: %s\n", mensagem);

    return 0;
}