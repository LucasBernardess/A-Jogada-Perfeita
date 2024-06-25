#include "../include/time_utils.h"
#include <stdio.h>

void calculateExecutionTime(struct timeval start, struct timeval end, struct rusage usageStart, struct rusage usageEnd) {
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double elapsed = seconds + microseconds*1e-6;

    printf("Elapsed time: %.6f seconds\n", elapsed);
    printf("User time: %ld.%06ld\n", usageEnd.ru_utime.tv_sec - usageStart.ru_utime.tv_sec, usageEnd.ru_utime.tv_usec - usageStart.ru_utime.tv_usec);
    printf("System time: %ld.%06ld\n", usageEnd.ru_stime.tv_sec - usageStart.ru_stime.tv_sec, usageEnd.ru_stime.tv_usec - usageStart.ru_stime.tv_usec);
}
