long long maximumTripletValue(int* nums, int numsSize) {
    if (numsSize < 3) return 0;
    
    long long maxVal = 0;
    
    // Arrays to store max left value and max right value
    int leftMax[numsSize];
    int rightMax[numsSize];
    
    // Fill leftMax where leftMax[i] is max nums[0] to nums[i-1]
    leftMax[0] = nums[0];
    for (int i = 1; i < numsSize; i++) {
        leftMax[i] = leftMax[i - 1] > nums[i] ? leftMax[i - 1] : nums[i];
    }
    
    // Fill rightMax where rightMax[i] is max nums[i+1] to nums[numsSize-1]
    rightMax[numsSize - 1] = nums[numsSize - 1];
    for (int i = numsSize - 2; i >= 0; i--) {
        rightMax[i] = rightMax[i + 1] > nums[i] ? rightMax[i + 1] : nums[i];
    }
    
    // Iterate for middle index and calculate the triplet value
    for (int j = 1; j < numsSize - 1; j++) {
        long long left = leftMax[j - 1];
        long long right = rightMax[j + 1];
        long long value = (left - nums[j]) * right;
        if (value > maxVal) {
            maxVal = value;
        }
    }
    
    return maxVal;
}
