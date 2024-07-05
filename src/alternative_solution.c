#include <stdlib.h>
#include <stdio.h>
#include "../include/alternative_solution.h"

unsigned long int maxAlternative(unsigned long int a, unsigned long int b) {
    return (a > b) ? a : b;
}

unsigned long int maxPointsBruteForce(unsigned long int* a, int n) {
    if (n == 0) return 0;
    if (n == 1) return a[0];
    if (n == 2) return maxAlternative(a[0], a[1]);
    
    unsigned long int maxPoints = 0;
    for (int i = 0; i < n; i++) {
        unsigned long int* newArray = (unsigned long int*)malloc((n - 2) * sizeof(unsigned long int));
        int k = 0;
        for (int j = 0; j < n; j++) {
            if (j == i || j == i-1 || j == i+1) continue;
            newArray[k++] = a[j];
        }
        maxPoints = maxAlternative(maxPoints, a[i] + maxPointsBruteForce(newArray, k));
        free(newArray);
    }
    return maxPoints;
}
