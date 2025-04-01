#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* partitionLabels(char* s, int* returnSize) {
    int lastIndex[26] = {0}; // Stores the last occurrence index of each character
    int length = strlen(s);

    // Populate last occurrence index for each character
    for (int i = 0; i < length; i++) {
        lastIndex[s[i] - 'a'] = i;
    }

    // Allocate memory for storing partition sizes
    int* result = (int*)malloc(length * sizeof(int));
    *returnSize = 0;

    int start = 0, end = 0;
    for (int i = 0; i < length; i++) {
        end = (lastIndex[s[i] - 'a'] > end) ? lastIndex[s[i] - 'a'] : end;

        // If current index reaches the last occurrence of a character, finalize the partition
        if (i == end) {
            result[(*returnSize)++] = end - start + 1;
            start = i + 1;
        }
    }

    return result;
}
