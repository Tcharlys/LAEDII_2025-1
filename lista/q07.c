#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 100

typedef struct {
    char nome[TAM_NOME];
    int matricula;
    float media;
} Aluno;

int main() {
    int n;
    printf("Informe o número de alunos: ");
    scanf("%d", &n);

    Aluno* alunos = (Aluno*)malloc(n * sizeof(Aluno));
    if (alunos == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Leitura dos dados dos alunos
    for (int i = 0; i < n; i++) {
        printf("\nAluno %d:\n", i + 1);

        printf("Nome: ");
        getchar(); // limpar buffer
        fgets(alunos[i].nome, TAM_NOME, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0'; // remove \n

        printf("Matrícula: ");
        scanf("%d", &alunos[i].matricula);

        printf("Média: ");
        scanf("%f", &alunos[i].media);
    }

    // Exibe os aprovados
    printf("\nAlunos aprovados (média >= 7.0):\n");
    for (int i = 0; i < n; i++) {
        if (alunos[i].media >= 7.0) {
            printf("Nome: %s | Matrícula: %d | Média: %.2f\n",
                   alunos[i].nome, alunos[i].matricula, alunos[i].media);
        }
    }

    free(alunos);
    return 0;
}