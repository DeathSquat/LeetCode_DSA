class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int max_val = *max_element(nums.begin(), nums.end());
        long long count = 0;
        int left = 0;
        int max_count = 0;

        for (int right = 0; right < n; ++right) {
            if (nums[right] == max_val) {
                max_count++;
            }

            // shrink the window until max_count < k
            while (max_count >= k) {
                count += (n - right); // all subarrays starting at left and ending at >= right
                if (nums[left] == max_val) {
                    max_count--;
                }
                left++;
            }
        }

        return count;
    }
};
