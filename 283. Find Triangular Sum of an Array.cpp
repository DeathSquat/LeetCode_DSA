class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        // Perform the process until only one element remains
        for (int size = n; size > 1; --size) {
            for (int i = 0; i < size - 1; ++i) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }
        return nums[0];
    }
};
