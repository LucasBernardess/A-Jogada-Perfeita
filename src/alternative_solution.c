#include <stdlib.h>
#include <stdio.h>
#include "../include/alternative_solution.h"

unsigned long int maxAlternative(unsigned long int a, unsigned long int b) {
    return (a > b) ? a : b;
}

unsigned long int maxPointsBruteForce(unsigned long int* a, int n, int i) {
    if (i >= n) {
        return 0;
    }

    unsigned long int valor1 = maxPointsBruteForce(a, n, i + 1);
    unsigned long int valor2 = a[i] + maxPointsBruteForce(a, n, i + 2);

    return maxAlternative(valor1, valor2);
}
