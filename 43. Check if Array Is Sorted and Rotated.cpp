class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        // Count the number of times the order is violated
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }
        
        // The array should have at most one drop to be a rotated sorted array
        return count <= 1;
    }
};
