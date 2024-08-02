# A Jogada Perfeita

## Introdução

João, um entusiasta de jogos, criou um jogo desafiador envolvendo uma sequência de números inteiros. Em cada jogada, um elemento e seus vizinhos são excluídos, rendendo pontos equivalentes ao valor do elemento escolhido. O objetivo é conseguir a maior pontuação possível. Este projeto desenvolve um programa para calcular a pontuação máxima, utilizando abordagens de força bruta e programação dinâmica.

## Estruturando a Solução

A solução é estruturada da seguinte forma:

1. Leitura de arquivos de entrada.
2. Estruturação do tabuleiro do jogo.
3. Implementação das soluções propostas (força bruta e programação dinâmica).
4. Salvamento dos resultados no arquivo de saída.

## Leitura de Arquivos

Os dados de entrada são fornecidos em um arquivo que contém:
- A primeira linha com o número de elementos da sequência.
- A segunda linha com os N inteiros da sequência.

A leitura dos dados é realizada utilizando a função `fscanf()` da biblioteca `stdlib.h`.

## Estruturação do Tabuleiro do Jogo

O tabuleiro do jogo é representado por um array criado a partir dos dados lidos do arquivo.

## Solução Proposta

### Força Bruta

Esta abordagem testa todas as combinações possíveis de jogadas na sequência de inteiros, registrando a maior pontuação obtida. Embora garanta a correção da solução, é ineficiente para sequências longas devido ao crescimento exponencial das chamadas recursivas.

### Programação Dinâmica

Esta abordagem divide o problema em subproblemas menores, armazenando os resultados intermediários para evitar cálculos redundantes. A solução é construída gradativamente, resultando em uma eficiência significativa em comparação com a força bruta.

## Estrutura de Dados

Utiliza-se a estrutura de dados `array` para representar a sequência de números. Esta escolha permite acesso direto e manipulação eficiente dos elementos, essencial para as operações frequentes de exclusão e cálculo de pontos em cada jogada.

### Modelagem Alternativa com Árvore de Decisão

Outra possível modelagem é utilizar uma árvore de decisão para representar as decisões de exclusão de elementos da sequência. Cada nó da árvore representa a decisão sobre um elemento específico, visualizando todas as possíveis sequências de jogadas.

## Estratégia de Resolução

### Força Bruta

A estratégia de força bruta utiliza chamadas recursivas para testar todas as possibilidades de maximização de pontos, resultando em uma complexidade temporal exponencial \(O(2^n)\).

### Programação Dinâmica

A abordagem de programação dinâmica utiliza uma relação de recorrência para construir a solução de forma eficiente, resultando em uma complexidade temporal linear \(O(n)\).

## Análise Matemática

### Algoritmo de Força Bruta

O algoritmo de força bruta possui uma complexidade temporal exponencial devido à exploração completa de todas as combinações possíveis.

### Algoritmo de Programação Dinâmica

A abordagem de programação dinâmica possui uma complexidade temporal linear, utilizando a relação de recorrência para evitar cálculos redundantes e garantir a eficiência.

## Testes

### Tempo do Algoritmo de Força Bruta

Os testes mostram que o tempo de execução do algoritmo de força bruta aumenta exponencialmente com o tamanho da entrada, tornando-o inviável para sequências maiores.

### Tempo do Algoritmo de Programação Dinâmica

O algoritmo de programação dinâmica apresenta um desempenho superior, lidando eficientemente com sequências de até 100.000 elementos, sem exceder 0,02 segundos de tempo de execução.

## Conclusão

Este projeto demonstrou a importância de analisar e comparar diferentes abordagens para a resolução de problemas complexos. A programação dinâmica provou ser uma solução robusta e eficiente, adequada para lidar com grandes volumes de dados. A escolha apropriada de estruturas de dados e algoritmos pode influenciar significativamente o desempenho de uma aplicação, garantindo soluções robustas e otimizadas.

## Referências

1. Thomas H. Cormen. Algoritmos: Teoria e prática. LTC, 2012.
2. Nivio Ziviani. Projetos de Algoritmos em C e Pascal. 2. ed. São Paulo: Cengage Learning, 2006.
3. Abrahim Ladha. CS 3510 Algorithms Lecture 9: Dynamic Programming I. 2023.
