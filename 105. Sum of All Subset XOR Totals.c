int subsetXORSumUtil(int* nums, int numsSize, int index, int currXOR) {
    if (index == numsSize) {
        return currXOR;
    }
    
    // Include the current element
    int include = subsetXORSumUtil(nums, numsSize, index + 1, currXOR ^ nums[index]);
    
    // Exclude the current element
    int exclude = subsetXORSumUtil(nums, numsSize, index + 1, currXOR);
    
    return include + exclude;
}

int subsetXORSum(int* nums, int numsSize) {
    return subsetXORSumUtil(nums, numsSize, 0, 0);
}
