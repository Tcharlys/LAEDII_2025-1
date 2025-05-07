#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM_PALAVRA 100
#define MAX_TENTATIVAS 6

// Função para exibir a imagem da forca
void exibirForca(int tentativas) {
    switch (tentativas) {
        case 0:
            printf("\n  -----\n  |   |\n      |\n      |\n      |\n      |\n--------\n");
            break;
        case 1:
            printf("\n  -----\n  |   |\n  O   |\n      |\n      |\n      |\n--------\n");
            break;
        case 2:
            printf("\n  -----\n  |   |\n  O   |\n  |   |\n      |\n      |\n--------\n");
            break;
        case 3:
            printf("\n  -----\n  |   |\n  O   |\n /|   |\n      |\n      |\n--------\n");
            break;
        case 4:
            printf("\n  -----\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n--------\n");
            break;
        case 5:
            printf("\n  -----\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n--------\n");
            break;
        case 6:
            printf("\n  -----\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n--------\n");
            break;
    }
}

// Função para mostrar a palavra com as letras descobertas
void mostrarPalavra(char palavra[], char palavraRevelada[]) {
    for (int i = 0; i < strlen(palavra); i++) {
        if (palavraRevelada[i] == '_') {
            printf("_ ");
        } else {
            printf("%c ", palavraRevelada[i]);
        }
    }
    printf("\n");
}

// Função principal do jogo da forca
int main() {
    char palavra[TAM_PALAVRA];
    char palavraRevelada[TAM_PALAVRA];
    char letrasErradas[MAX_TENTATIVAS];
    char letra;
    int tentativas = 0;
    int acertou = 0;

    // Solicita a palavra a ser adivinhada
    printf("Digite a palavra a ser adivinhada: ");
    fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = '\0';  // Remove o '\n' no final da entrada

    // Inicializa a palavra revelada com underscores
    for (int i = 0; i < strlen(palavra); i++) {
        palavraRevelada[i] = '_';
    }
    palavraRevelada[strlen(palavra)] = '\0';

    // Inicia o vetor de letras erradas
    for (int i = 0; i < MAX_TENTATIVAS; i++) {
        letrasErradas[i] = '\0';
    }

    // Inicia o jogo
    while (tentativas < MAX_TENTATIVAS) {
        printf("\nTentativa %d de %d\n", tentativas + 1, MAX_TENTATIVAS);
        mostrarPalavra(palavra, palavraRevelada);
        printf("\nLetras erradas: ");
        for (int i = 0; i < tentativas; i++) {
            printf("%c ", letrasErradas[i]);
        }

        exibirForca(tentativas);  // Exibe a imagem da forca com base nas tentativas

        // Solicita uma letra do jogador
        printf("\nDigite uma letra: ");
        scanf(" %c", &letra);
        letra = tolower(letra);  // Converte a letra para minúscula

        // Verifica se a letra já foi tentada antes
        int letraJaTentada = 0;
        for (int i = 0; i < tentativas; i++) {
            if (letrasErradas[i] == letra || palavraRevelada[i] == letra) {
                letraJaTentada = 1;
                break;
            }
        }

        if (letraJaTentada) {
            printf("Você já tentou essa letra. Tente outra.\n");
            continue;
        }

        // Verifica se a letra está na palavra
        int letraCorreta = 0;
        for (int i = 0; i < strlen(palavra); i++) {
            if (palavra[i] == letra) {
                palavraRevelada[i] = letra;
                letraCorreta = 1;
            }
        }

        // Se a letra estiver errada, registra no vetor de letras erradas
        if (!letraCorreta) {
            letrasErradas[tentativas] = letra;
            tentativas++;
            printf("A letra '%c' não está na palavra.\n", letra);
        }

        // Verifica se o jogador acertou a palavra
        if (strcmp(palavra, palavraRevelada) == 0) {
            acertou = 1;
            break;
        }
    }

    // Finaliza o jogo
    if (acertou) {
        printf("\nParabéns, você acertou a palavra: %s!\n", palavra);
    } else {
        exibirForca(tentativas);  // Exibe a forca final caso o jogador perca
        printf("\nVocê perdeu! A palavra era: %s\n", palavra);
    }

    return 0;
}