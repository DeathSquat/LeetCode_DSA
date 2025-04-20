#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numRabbits(int* answers, int answersSize) {
    int count[1001] = {0};
    for (int i = 0; i < answersSize; i++) {
        count[answers[i]]++;
    }

    int totalRabbits = 0;
    for (int i = 0; i < 1000; i++) {
        if (count[i] > 0) {
            int groupSize = i + 1;
            int groups = (count[i] + groupSize - 1) / groupSize; // Ceiling of count[i] / groupSize
            totalRabbits += groups * groupSize;
        }
    }

    return totalRabbits;
}
