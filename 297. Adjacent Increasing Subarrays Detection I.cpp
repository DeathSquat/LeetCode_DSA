class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Helper function to check if a subarray is strictly increasing
        auto isStrictlyIncreasing = [&](int start) {
            for (int i = start; i < start + k - 1; ++i) {
                if (nums[i] >= nums[i + 1]) {
                    return false;
                }
            }
            return true;
        };

        // Iterate through the array and check each possible pair of adjacent subarrays
        for (int i = 0; i <= n - 2 * k; ++i) {
            if (isStrictlyIncreasing(i) && isStrictlyIncreasing(i + k)) {
                return true;
            }
        }
        
        return false;
    }
};
