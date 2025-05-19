class Solution {
public:
    string triangleType(vector<int>& nums) {
        // Sort the sides to simplify the triangle inequality check
        sort(nums.begin(), nums.end());
        
        // Check if the sides can form a triangle using the triangle inequality theorem
        if (nums[0] + nums[1] <= nums[2]) {
            return "none";
        }

        // Check for triangle type
        if (nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        } else if (nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) {
            return "isosceles";
        } else {
            return "scalene";
        }
    }
};
