#include <stdlib.h>
#include <stdio.h>
#include "../include/alternative_solution.h"
#include "utils.h"

unsigned long int maxPointsBruteForce(unsigned long int* a, int n, int i) {
    if (i >= n) {
        return 0;
    }

    unsigned long int valor1 = maxPointsBruteForce(a, n, i + 1);
    unsigned long int valor2 = a[i] + maxPointsBruteForce(a, n, i + 2);

    return max(valor1, valor2);
}
