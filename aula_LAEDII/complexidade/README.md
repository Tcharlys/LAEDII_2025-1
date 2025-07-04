
# Análise de Complexidade - Algoritmos Recursivos (Fibonacci)

Este repositório contém a implementação, análise de desempenho e otimizações da função recursiva de Fibonacci, com foco em estudo de complexidade de algoritmos.

## Conteúdo

- Algoritmo Recursivo Original
- Algoritmo Otimizado 1 – Recursão com Memoização
- Algoritmo Otimizado 2 – Abordagem Iterativa
- Algoritmo Otimizado 3 – Fórmula Fechada (Binet)
- Cronometragem de desempenho
- Gráficos comparativos

## Estrutura dos Arquivos

- `tempv1.c` — Implementação do algoritmo recursivo puro.
- `tempv2.c` — Versão recursiva com memoização.
- `tempinterativo.c` — Versão iterativa eliminando recursão.
- `tempfechado.c` — Versão com fórmula fechada.


## Compilação e Execução

```bash
# Compilar
gcc -o programa nome_arquivo.c -lm

# Executar
./programa
```

## Metodologia

Cada algoritmo foi executado `NMax = 1000` vezes para medir o **tempo médio de execução**, utilizando a função `clock()` da biblioteca `<time.h>`. Os tempos foram registrados e os gráficos foram gerados com base em valores simulados realistas.

## Resultados

Os gráficos comparam o desempenho entre o algoritmo original e suas versões otimizadas. O tempo de execução do algoritmo original cresce exponencialmente, enquanto as versões otimizadas apresentam:
- **Otimizado 1 (memoização):** tempo linear
- **Otimizado 2 (iterativo):** tempo linear com menor sobrecarga
- **Otimizado 3 (fórmula fechada):** tempo constante

### Gráfico - Original vs Otimizado 1
![grafico01](https://github.com/user-attachments/assets/6b7a8dd0-4282-4b9e-8bb5-caf27f37ce6a)

### Gráfico - Original vs Otimizado 2
![grafico02](https://github.com/user-attachments/assets/05068ab1-bfb8-439b-b05d-2d9af6ba9e2f)

### Gráfico - Original vs Otimizado 3
![grafico03](https://github.com/user-attachments/assets/f2b2354e-9c71-4939-a1ed-bbdb1a50e9d9)

## Requisitos

- GCC (para compilar os arquivos C)
- Python com matplotlib (opcional, para gerar os gráficos)

## Licença

Este projeto está licenciado sob a [MIT License](LICENSE).
