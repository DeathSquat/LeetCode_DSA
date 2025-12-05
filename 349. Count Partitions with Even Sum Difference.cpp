class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        
        // Step 1: Calculate the total sum of the array
        for (int num : nums) {
            totalSum += num;
        }
        
        int leftSum = 0;
        int rightSum = totalSum;
        int count = 0;
        
        // Step 2: Iterate over possible partition points
        for (int i = 0; i < n - 1; ++i) {
            leftSum += nums[i];
            rightSum -= nums[i];
            
            // Check if both left and right sums have the same parity
            if (leftSum % 2 == rightSum % 2) {
                count++;
            }
        }
        
        return count;
    }
};
