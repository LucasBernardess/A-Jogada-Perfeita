#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "../include/alternative_solution.h"

// Estratégia utilizando força bruta
unsigned long int maxPointsBruteForce(unsigned long int* points, int quantity, int currentIndex) {
    // Verificação inicial
    if (currentIndex >= quantity) {
        return 0;
    }

    unsigned long int valueA = maxPointsBruteForce(points, quantity, currentIndex + 1);
    unsigned long int valueB = points[currentIndex] + maxPointsBruteForce(points, quantity, currentIndex + 2);

    return max(valueA, valueB);
}