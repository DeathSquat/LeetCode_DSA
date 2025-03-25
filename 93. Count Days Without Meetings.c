#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int **)a)[0] - (*(int **)b)[0];
}

int countDays(int days, int** meetings, int meetingsSize, int* meetingsColSize) {
    if (meetingsSize == 0) return days;

    // Sort meetings by start time
    qsort(meetings, meetingsSize, sizeof(meetings[0]), compare);

    int freeDays = 0;
    int currentDay = 1;

    for (int i = 0; i < meetingsSize; i++) {
        int start = meetings[i][0];
        int end = meetings[i][1];

        if (currentDay < start) {
            freeDays += start - currentDay;
        }
        currentDay = (currentDay < end + 1) ? end + 1 : currentDay;
    }

    // Count remaining free days after last meeting
    if (currentDay <= days) {
        freeDays += days - currentDay + 1;
    }

    return freeDays;
}
