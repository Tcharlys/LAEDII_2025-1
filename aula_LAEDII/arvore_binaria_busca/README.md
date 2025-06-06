# Estruturas de Dados: Árvores Binárias de Busca em C

Este repositório contém dois algoritmos implementados em linguagem C utilizando **árvores binárias de busca (ABB)**. As implementações cobrem operações fundamentais de manipulação de árvores e armazenam dois tipos de dados:

1. **Números inteiros** — estrutura básica de ABB.
2. **Registros de alunos** — estrutura com ordenação por nome.

---

## 📁 Estrutura dos Códigos

### 1. `bst.c`

Implementa uma árvore binária de busca para armazenar e manipular números inteiros.

#### Funcionalidades:
- Inserção, busca e remoção de nós
- Percursos:
  - Em ordem (in-order)
  - Pré-ordem (pre-order)
  - Pós-ordem (post-order)
- Cálculo de:
  - Altura da árvore
  - Profundidade e nível de um nó
  - Soma dos valores
  - Total de nós e folhas

### 2. `aluno.c`

Extende o conceito de ABB para armazenar registros de alunos, ordenando-os por **nome**.

#### Funcionalidades adicionais:
- Inserção e busca de alunos
- Cálculo da média das notas
- Liberação completa de memória da árvore de alunos

---

## 🧱 Estruturas de Dados

### Nó de Inteiros
```c
typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
} No;
```

### Nó de Aluno
```c
typedef struct Aluno {
    char nome[50];
    int matricula;
    float nota;
    struct Aluno* esquerdo;
    struct Aluno* direito;
} Aluno;
```

---

## ⚙️ Compilação e Execução

### Compilar
```bash
gcc nome_do_arquivo.c -o exec
```

### Executar
```bash
./exec
```

> Substitua `bst.c` por `bst` ou `alunos.c`.

---

## 📌 Exemplo de Saída

```
Em ordem: 3 5 7 10 15 
Pre-ordem: 10 5 3 7 15 
Pos-ordem: 3 7 5 15 10 
Altura: 2
Profundidade do nó 7: 2
Soma dos valores: 40
Nível do nó 3: 2
Total de nós: 5
Total de folhas: 2
Aluno encontrado: Bruno, Matrícula: 3, Nota: 9.20
Média das notas: 8.23
```

---

## ✅ Requisitos

- Compilador C (`gcc`)
- Ambiente POSIX (Linux, Unix, WSL, ou Windows com suporte a execução de binários)

---

## 📄 Licença

Código livre para uso acadêmico e educacional.
