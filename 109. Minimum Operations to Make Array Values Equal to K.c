#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmpDesc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

bool exists(int* arr, int size, int val) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) return true;
    }
    return false;
}

int minOperations(int* nums, int numsSize, int k) {
    // Step 1: Check for invalid condition
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < k) return -1;
    }

    // Step 2: Collect unique values > k
    int unique[101] = {0}; // nums[i] <= 100
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > k && !unique[nums[i]]) {
            unique[nums[i]] = 1;
            count++;
        }
    }

    if (count == 0) return 0;

    int* vals = (int*)malloc(count * sizeof(int));
    int idx = 0;
    for (int i = 100; i >= 0; i--) {
        if (unique[i]) {
            vals[idx++] = i;
        }
    }

    int ops = 0;
    for (int i = 0; i < count; i++) {
        ops++;
        if (vals[i] == k) break;
    }

    free(vals);
    return ops;
}
