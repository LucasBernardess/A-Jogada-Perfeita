#ifndef TIME_UTILS_H
#define TIME_UTILS_H

void calculateExecutionTime(struct timeval start, struct timeval end, struct rusage usageStart, struct rusage usageEnd);

#endif