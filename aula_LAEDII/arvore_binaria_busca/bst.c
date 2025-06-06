// Estrutura de dados para árvore binária de busca
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó
typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
} No;

// Criação de um nó
No* criarNo(int c) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo != NULL) {
        novo->dado = c;
        novo->esquerdo = NULL;
        novo->direito = NULL;
    }
    return novo;
}

// Remoção de todos os nós
void remover(No* T) {
    if (T != NULL) {
        remover(T->esquerdo);
        remover(T->direito);
        free(T);
    }
}

// Busca de um nó
No* buscar(No* T, int c) {
    if (T == NULL || T->dado == c) return T;
    if (c < T->dado) return buscar(T->esquerdo, c);
    else return buscar(T->direito, c);
}

// Inserção de um nó
No* inserir(No* T, int c) {
    if (T == NULL) return criarNo(c);
    if (c < T->dado) T->esquerdo = inserir(T->esquerdo, c);
    else if (c > T->dado) T->direito = inserir(T->direito, c);
    return T;
}

// Percurso em ordem
void emOrdem(No* T) {
    if (T != NULL) {
        emOrdem(T->esquerdo);
        printf("%d ", T->dado);
        emOrdem(T->direito);
    }
}

// Percurso em pré-ordem
void preOrdem(No* T) {
    if (T != NULL) {
        printf("%d " ,T->dado);
        preOrdem(T->esquerdo);
        preOrdem(T->direito);
    }
}

// Percurso em pós-ordem
void posOrdem(No* T) {
    if (T != NULL) {
        posOrdem(T->esquerdo);
        posOrdem(T->direito);
        printf("%d ", T->dado);
    }
}

// Altura da árvore
int altura(No* T) {
    if (T == NULL) return -1;
    int ae = altura(T->esquerdo);
    int ad = altura(T->direito);
    return (ae > ad ? ae : ad) + 1;
}

// Profundidade de um nó
int profundidade(No* T, int c, int nivel) {
    if (T == NULL) return -1;
    if (T->dado == c) return nivel;
    if (c < T->dado) return profundidade(T->esquerdo, c, nivel + 1);
    else return profundidade(T->direito, c, nivel + 1);
}

// Soma dos valores
int soma(No* T) {
    if (T == NULL) return 0;
    return T->dado + soma(T->esquerdo) + soma(T->direito);
}

// Nível de um nó (igual profundidade)
int nivel(No* T, int c) {
    return profundidade(T, c, 0);
}

// Número de nós
int contarNos(No* T) {
    if (T == NULL) return 0;
    return 1 + contarNos(T->esquerdo) + contarNos(T->direito);
}

// Número de folhas
int contarFolhas(No* T) {
    if (T == NULL) return 0;
    if (T->esquerdo == NULL && T->direito == NULL) return 1;
    return contarFolhas(T->esquerdo) + contarFolhas(T->direito);
}

int main() {
    No* raiz = NULL;

    // Inserções
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 7);

    // Percursos
    printf("Em ordem: ");
    emOrdem(raiz); printf("\n");
    printf("Pre-ordem: ");
    preOrdem(raiz); printf("\n");
    printf("Pos-ordem: ");
    posOrdem(raiz); printf("\n");

    // Altura
    printf("Altura: %d\n", altura(raiz));

    // Profundidade de um nó
    printf("Profundidade do nó 7: %d\n", profundidade(raiz, 7, 0));

    // Soma dos valores
    printf("Soma dos valores: %d\n", soma(raiz));

    // Nível
    printf("Nível do nó 3: %d\n", nivel(raiz, 3));

    // Número de nós
    printf("Total de nós: %d\n", contarNos(raiz));

    // Número de folhas
    printf("Total de folhas: %d\n", contarFolhas(raiz));

    // Limpar árvore
    remover(raiz);

    return 0;
}