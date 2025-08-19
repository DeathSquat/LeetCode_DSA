class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;   // Final answer
        long long streak = 0;  // Current consecutive zeros
        
        for (int num : nums) {
            if (num == 0) {
                streak++;           // Extend the zero streak
                count += streak;    // Add all subarrays ending here
            } else {
                streak = 0;         // Reset streak when non-zero found
            }
        }
        
        return count;
    }
};
