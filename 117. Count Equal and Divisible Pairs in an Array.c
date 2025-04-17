int countPairs(int* nums, int numsSize, int k) {
    int count = 0;
    
    // Loop through all pairs (i, j) such that i < j
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            // Check if nums[i] == nums[j] and (i * j) % k == 0
            if (nums[i] == nums[j] && (i * j) % k == 0) {
                count++;
            }
        }
    }
    
    return count;
}
