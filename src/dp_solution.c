#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "../include/dp_solution.h"

// Estratégia utilizando programação dinâmica
long int maxPointsDP(long int* points, int quantity) {
    // Verificações iniciais
    if (quantity == 0) return 0;
    if (quantity == 1) return points[0];
    if (quantity == 2) return max(points[0], points[1]);
    
    // Aloca memória para o array dp
    long int* dp = (long int*)malloc(quantity * sizeof(long int));

    // Inicializando o 2 primeiros valores
    dp[0] = points[0];
    dp[1] = max(points[0], points[1]);

    // Calculando os outros valores do array dp, utilizando a relação de recorrência
    for (int i = 2; i < quantity; i++) {
        dp[i] = max(dp[i-1], points[i] + dp[i-2]);
    }
    
    // Puxando o último valor do array dp, pois é o resultado final
    long int result = dp[quantity-1];
    free(dp);
    return result;
}