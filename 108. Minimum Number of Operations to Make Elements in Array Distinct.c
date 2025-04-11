#include <stdbool.h>

int minimumOperations(int* nums, int numsSize) {
    int operations = 0;
    int i = 0;

    while (i < numsSize) {
        bool seen[101] = {false};
        bool hasDuplicate = false;

        // Check if the current array has any duplicates
        for (int j = i; j < numsSize; j++) {
            if (seen[nums[j]]) {
                hasDuplicate = true;
                break;
            }
            seen[nums[j]] = true;
        }

        // If there are no duplicates, we're done
        if (!hasDuplicate) {
            break;
        }

        // Otherwise, remove the first 3 elements
        i += 3;
        operations++;
    }

    return operations;
}
