#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 100
#define TAM_TEL 20
#define MAX_CONTATOS 1000

typedef struct {
    char nome[TAM_NOME];
    char telefone[TAM_TEL];
} Contato;

void adicionarContato(Contato contatos[], int* total) {
    if (*total >= MAX_CONTATOS) {
        printf("Limite de contatos atingido.\n");
        return;
    }

    printf("Nome: ");
    getchar(); // limpar buffer
    fgets(contatos[*total].nome, TAM_NOME, stdin);
    contatos[*total].nome[strcspn(contatos[*total].nome, "\n")] = '\0';

    printf("Telefone: ");
    fgets(contatos[*total].telefone, TAM_TEL, stdin);
    contatos[*total].telefone[strcspn(contatos[*total].telefone, "\n")] = '\0';

    (*total)++;
    printf("Contato adicionado com sucesso.\n");
}

void buscarContato(Contato contatos[], int total) {
    char busca[TAM_NOME];
    printf("Digite o nome a buscar: ");
    getchar(); // limpar buffer
    fgets(busca, TAM_NOME, stdin);
    busca[strcspn(busca, "\n")] = '\0';

    int encontrado = 0;
    for (int i = 0; i < total; i++) {
        if (strcmp(contatos[i].nome, busca) == 0) {
            printf("Contato encontrado:\n");
            printf("Nome: %s | Telefone: %s\n", contatos[i].nome, contatos[i].telefone);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Contato '%s' não encontrado.\n", busca);
    }
}

void listarContatos(Contato contatos[], int total) {
    if (total == 0) {
        printf("Nenhum contato cadastrado.\n");
        return;
    }

    printf("\nLista de Contatos:\n");
    for (int i = 0; i < total; i++) {
        printf("Contato %d:\n", i + 1);
        printf("  Nome: %s\n", contatos[i].nome);
        printf("  Telefone: %s\n", contatos[i].telefone);
    }
}

int main() {
    Contato contatos[MAX_CONTATOS];
    int total = 0, opcao;

    do {
        printf("\nMenu:\n");
        printf("1 - Adicionar contato\n");
        printf("2 - Buscar contato por nome\n");
        printf("3 - Listar todos os contatos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato(contatos, &total);
                break;
            case 2:
                buscarContato(contatos, total);
                break;
            case 3:
                listarContatos(contatos, total);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}