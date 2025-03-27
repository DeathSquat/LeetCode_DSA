#include <stdio.h>
#include <stdlib.h>

int minimumIndex(int* nums, int numsSize) {
    // Step 1: Find the dominant element
    int candidate = nums[0], count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    // Step 2: Count occurrences of the dominant element
    int totalCount = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate) {
            totalCount++;
        }
    }

    // Step 3: Find the minimum valid split index
    int leftCount = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == candidate) {
            leftCount++;
        }
        int rightCount = totalCount - leftCount;
        if (leftCount * 2 > (i + 1) && rightCount * 2 > (numsSize - i - 1)) {
            return i;
        }
    }

    return -1;
}
