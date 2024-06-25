#include "../include/dp_solution.h"
#include <stdlib.h>

int dp_solution(int *sequence, int n) {
    // Implementação da solução usando Programação Dinâmica
    int *dp = (int *)malloc((n + 1) * sizeof(int));
    if (!dp) return 0;

    // Inicialização e lógica da DP
    // ...

    int result = dp[n];
    free(dp);
    return result;
}
