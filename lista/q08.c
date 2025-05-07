#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 100
#define MAX_PRODUTOS 1000

typedef struct {
    char nome[TAM_NOME];
    int codigo;
    int quantidade;
    float preco;
} Produto;

void cadastrarProduto(Produto produtos[], int* total) {
    if (*total >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido.\n");
        return;
    }

    printf("Cadastro do Produto %d:\n", *total + 1);
    printf("Nome: ");
    getchar(); // limpar buffer
    fgets(produtos[*total].nome, TAM_NOME, stdin);
    produtos[*total].nome[strcspn(produtos[*total].nome, "\n")] = '\0';

    printf("Código: ");
    scanf("%d", &produtos[*total].codigo);

    printf("Quantidade: ");
    scanf("%d", &produtos[*total].quantidade);

    printf("Preço: ");
    scanf("%f", &produtos[*total].preco);

    (*total)++;
}

void buscarProduto(Produto produtos[], int total) {
    int cod;
    printf("Digite o código do produto a buscar: ");
    scanf("%d", &cod);

    for (int i = 0; i < total; i++) {
        if (produtos[i].codigo == cod) {
            printf("Produto encontrado:\n");
            printf("Nome: %s\n", produtos[i].nome);
            printf("Código: %d\n", produtos[i].codigo);
            printf("Quantidade: %d\n", produtos[i].quantidade);
            printf("Preço: %.2f\n", produtos[i].preco);
            return;
        }
    }
    printf("Produto com código %d não encontrado.\n", cod);
}

void listarProdutos(Produto produtos[], int total) {
    if (total == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("\nLista de Produtos:\n");
    for (int i = 0; i < total; i++) {
        printf("Produto %d:\n", i + 1);
        printf("  Nome: %s\n", produtos[i].nome);
        printf("  Código: %d\n", produtos[i].codigo);
        printf("  Quantidade: %d\n", produtos[i].quantidade);
        printf("  Preço: %.2f\n", produtos[i].preco);
    }
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    int total = 0, opcao;

    do {
        printf("\nMenu:\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Buscar produto por código\n");
        printf("3 - Listar todos os produtos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto(produtos, &total);
                break;
            case 2:
                buscarProduto(produtos, total);
                break;
            case 3:
                listarProdutos(produtos, total);
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