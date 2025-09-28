class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // Sort the array in non-decreasing order
        sort(nums.begin(), nums.end());
        
        // Start from the largest numbers and check if they can form a triangle
        for (int i = nums.size() - 1; i >= 2; --i) {
            // Triangle inequality: sum of two smaller sides > largest side
            if (nums[i - 2] + nums[i - 1] > nums[i]) {
                return nums[i - 2] + nums[i - 1] + nums[i];
            }
        }
        
        // If no valid triangle found
        return 0;
    }
};
