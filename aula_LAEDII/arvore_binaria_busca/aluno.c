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

// Estrutura do nó com dados de aluno
typedef struct Aluno {
    char nome[50];
    int matricula;
    float nota;
    struct Aluno* esquerdo;
    struct Aluno* direito;
} Aluno;

// Criação de um nó de aluno
Aluno* criarAluno(const char* nome, int matricula, float nota) {
    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    if (novo != NULL) {
        strcpy(novo->nome, nome);
        novo->matricula = matricula;
        novo->nota = nota;
        novo->esquerdo = NULL;
        novo->direito = NULL;
    }
    return novo;
}

// Inserção de aluno com base no nome
Aluno* inserirAluno(Aluno* T, const char* nome, int matricula, float nota) {
    if (T == NULL) return criarAluno(nome, matricula, nota);
    int cmp = strcmp(nome, T->nome);
    if (cmp < 0) T->esquerdo = inserirAluno(T->esquerdo, nome, matricula, nota);
    else if (cmp > 0) T->direito = inserirAluno(T->direito, nome, matricula, nota);
    return T;
}

// Buscar aluno pelo nome
Aluno* buscarAluno(Aluno* T, const char* nome) {
    if (T == NULL) return NULL;
    int cmp = strcmp(nome, T->nome);
    if (cmp == 0) return T;
    else if (cmp < 0) return buscarAluno(T->esquerdo, nome);
    else return buscarAluno(T->direito, nome);
}

// Soma das notas e contagem de alunos para média
float somaNotas(Aluno* T, int* cont) {
    if (T == NULL) return 0.0;
    float somaE = somaNotas(T->esquerdo, cont);
    float somaD = somaNotas(T->direito, cont);
    (*cont)++;
    return somaE + somaD + T->nota;
}

float mediaNotas(Aluno* T) {
    int cont = 0;
    float soma = somaNotas(T, &cont);
    return (cont == 0) ? 0.0 : soma / cont;
}

// Liberação da árvore de alunos
void removerAlunos(Aluno* T) {
    if (T != NULL) {
        removerAlunos(T->esquerdo);
        removerAlunos(T->direito);
        free(T);
    }
}

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

    // Questão 2 - Testes com estrutura Aluno
    Aluno* turma = NULL;
    turma = inserirAluno(turma, "Ana", 1, 8.5);
    turma = inserirAluno(turma, "Carlos", 2, 7.0);
    turma = inserirAluno(turma, "Bruno", 3, 9.2);

    Aluno* a = buscarAluno(turma, "Bruno");
    if (a != NULL) {
        printf("Aluno encontrado: %s, Matrícula: %d, Nota: %.2f\n", a->nome, a->matricula, a->nota);
    } else {
        printf("Aluno não encontrado.\n");
    }

    printf("Média das notas: %.2f\n", mediaNotas(turma));

    // Liberação de memória
    remover(raiz);
    removerAlunos(turma);

    return 0;
}