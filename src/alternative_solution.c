#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "../include/alternative_solution.h"

// Estratégia utilizando força bruta
long int maxPointsBruteForce(long int* points, int quantity, int currentIndex) {
    // Verificação inicial
    if (currentIndex >= quantity) {
        return 0;
    }

    long int valueA = maxPointsBruteForce(points, quantity, currentIndex + 1);
    long int valueB = points[currentIndex] + maxPointsBruteForce(points, quantity, currentIndex + 2);

    return max(valueA, valueB);
}