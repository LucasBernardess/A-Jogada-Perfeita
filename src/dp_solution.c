#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "../include/dp_solution.h"

unsigned long int maxPointsDP(unsigned long int* a, int n) {
    if (n == 0) return 0;
    if (n == 1) return a[0];
    if (n == 2) return max(a[0], a[1]);
    
    unsigned long int* dp = (unsigned long int*)malloc(n * sizeof(unsigned long int));
    dp[0] = a[0];
    dp[1] = max(a[0], a[1]);
    
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], a[i] + dp[i-2]);
    }
    
    unsigned long int result = dp[n-1];
    free(dp);
    return result;
}