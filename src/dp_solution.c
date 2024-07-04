#include <stdlib.h>
#include <stdio.h>
#include "../include/dp_solution.h"

// Função para encontrar o valor máximo usando programação dinâmica
int dp_solution(int *sequence, int n) {
    if (n == 0) return 0;
    if (n == 1) return sequence[0];

    // Tabela para armazenar resultados de subproblemas
    int *dp = (int *)malloc((n + 1) * sizeof(int));
    
    // Inicialização
    dp[0] = 0;
    dp[1] = sequence[0];

    // Preenchimento da tabela dp
    for (int i = 2; i <= n; i++) {
        dp[i] = sequence[i-1] + dp[i-2]; // Caso inclua a sequência atual
        if (i > 2) {
            dp[i] = (dp[i] > sequence[i-1] + dp[i-3]) ? dp[i] : sequence[i-1] + dp[i-3]; // Caso exclua um elemento adicional
        }
        dp[i] = (dp[i] > dp[i-1]) ? dp[i] : dp[i-1]; // Melhor escolha até o elemento atual
    }

    int result = dp[n];
    free(dp);
    return result;
}