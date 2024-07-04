#include <stdlib.h>
#include <stdio.h>
#include "../include/dp_solution.h"

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxPointsDP(int* a, int n) {
    if (n == 0) return 0;
    if (n == 1) return a[0];
    
    int* dp = (int*)malloc(n * sizeof(int));
    dp[0] = a[0];
    dp[1] = max(a[0], a[1]);
    
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], a[i] + dp[i-2]);
    }
    
    int result = dp[n-1];
    free(dp);
    return result;
}