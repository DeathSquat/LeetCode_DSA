class Solution {
public:
    int maxOr = 0;
    int count = 0;
    
    void backtrack(vector<int>& nums, int index, int currentOr) {
        if (index == nums.size()) {
            if (currentOr == maxOr)
                count++;
            return;
        }
        
        // Include current element
        backtrack(nums, index + 1, currentOr | nums[index]);
        
        // Exclude current element
        backtrack(nums, index + 1, currentOr);
    }
    
    int countMaxOrSubsets(vector<int>& nums) {
        // First, calculate the maximum OR possible
        for (int num : nums)
            maxOr |= num;
        
        // Now use backtracking to count subsets with that OR
        backtrack(nums, 0, 0);
        
        return count;
    }
};
