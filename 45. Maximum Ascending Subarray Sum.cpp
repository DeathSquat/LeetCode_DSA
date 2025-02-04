class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0, currentSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                currentSum += nums[i];  // Continue the ascending subarray
            } else {
                maxSum = max(maxSum, currentSum);  // Update maxSum if needed
                currentSum = nums[i];  // Start a new subarray
            }
        }
        
        return max(maxSum, currentSum);  // Final check to return max sum
    }
};
