#include <stdlib.h>
#include <stdio.h>
#include "../include/alternative_solution.h"

int maxAlternative(int a, int b) {
    return (a > b) ? a : b;
}

int maxPointsBruteForce(int* a, int n) {
    if (n == 0) return 0;
    if (n == 1) return a[0];
    
    int maxPoints = 0;
    for (int i = 0; i < n; i++) {
        int* newArray = (int*)malloc((n - 2) * sizeof(int));
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
