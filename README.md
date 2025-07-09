# Métodos Numéricos para Sistemas Lineares em C++

Este repositório contém implementações em C++ de diversos métodos numéricos diretos para a resolução de sistemas de equações lineares, cálculo de matriz inversa e decomposições de matrizes.

## Visão Geral

O projeto fornece um conjunto de funções para realizar operações fundamentais da álgebra linear numérica. Foi desenvolvido como uma ferramenta para estudar e aplicar métodos para resolver sistemas do tipo $Ax = b$, encontrar a inversa $A^{-1}$ e realizar decomposições como LU, Cholesky e QR.

## Métodos Implementados

A biblioteca inclui os seguintes métodos:

### 1. Eliminação Gaussiana
- **Com Pivoteamento Parcial (`eliminacaoGaussPP`):** Estratégia de pivoteamento que troca linhas para selecionar o maior elemento em módulo na coluna atual como pivô. Isso aumenta a estabilidade numérica do método.
- **Com Pivoteamento Total (`eliminacaoGaussPT`):** Estratégia de pivoteamento mais robusta que busca o maior elemento em módulo em toda a submatriz restante, trocando tanto linhas quanto colunas para usá-lo como pivô.

### 2. Decomposição LU
- **`decLU`:** Fatora uma matriz $A$ em um produto de uma matriz triangular inferior ($L$) e uma matriz triangular superior ($U$). A implementação atual utiliza pivoteamento total para maior estabilidade. Após a decomposição, o sistema $Ax = b$ é resolvido eficientemente em duas etapas: $Ly = b$ e $Ux = y$.
- **`decLUInversa`:** Utiliza a decomposição LU para calcular a matriz inversa de $A$. Resolve o sistema $Ax = e_j$ para cada coluna $e_j$ da matriz identidade, onde as soluções $x$ se tornam as colunas da matriz inversa $A^{-1}$.

### 3. Decomposição de Cholesky
- **`cholesky`:** Implementa a decomposição de Cholesky, um método altamente eficiente que fatora uma matriz simétrica e definida positiva $A$ em um produto $A = CC^T$, onde $C$ é uma matriz triangular inferior. O código verifica se a matriz atende à condição de ser definida positiva durante o processo.

### 4. Decomposição QR
A decomposição QR fatora uma matriz $A$ em um produto $A = QR$, onde $Q$ é uma matriz ortogonal ($Q^T Q = I$) e $R$ é uma matriz triangular superior. Foram implementadas três abordagens clássicas:
- **Reflexões de Householder (`decomposicaoQR_Householder`):** Utiliza uma sequência de reflexões para zerar os elementos abaixo da diagonal principal.
- **Rotações de Givens (`decomposicaoQR_Givens`):** Aplica uma série de rotações no plano para anular seletivamente os elementos subdiagonais. É particularmente útil para matrizes esparsas.
- **Processo de Gram-Schmidt (`decomposicaoQR_GramSchmidt`):** Ortonormaliza as colunas da matriz $A$ para formar as colunas da matriz ortogonal $Q$.

## Estrutura do Projeto

O código está organizado nos seguintes arquivos:

- **`main.cpp`**: Arquivo principal que inicializa uma matriz e um vetor, e chama os diferentes métodos numéricos para demonstrar seu funcionamento e exibir os resultados.
- **`metodos_diretos.hpp` / `metodos_diretos.cpp`**: Contêm as implementações da Eliminação Gaussiana, Decomposição LU e Cholesky.
- **`QR.hpp` / `QR.cpp`**: Contêm as implementações das decomposições QR (Householder, Givens e Gram-Schmidt) e funções auxiliares para operações com matrizes.
- **`triangular.hpp` / `triangular.cpp`**: Contêm funções para resolver sistemas triangulares (superiores e inferiores), que são usadas como etapas finais nos métodos de decomposição.

## Como Compilar e Executar

Você precisará de um compilador C++ (como g++) para compilar o projeto.

1.  **Clone o repositório:**
    ```bash
    git clone <URL_DO_REPOSITORIO>
    cd <NOME_DO_DIRETORIO>
    ```

2.  **Compile os arquivos-fonte:**
    ```bash
    g++ -o main main.cpp metodos_diretos.cpp triangular.cpp QR.cpp -std=c++11
    ```

3.  **Execute o programa:**
    ```bash
    ./main
    ```

O programa irá imprimir a matriz original $A$ e o vetor $b$, seguidos pelas soluções e matrizes resultantes de cada um dos métodos implementados.

