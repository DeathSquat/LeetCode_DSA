class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, zeros = 0, ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeros++;

            // Shrink window if more than 1 zero
            while (zeros > 1) {
                if (nums[left] == 0) zeros--;
                left++;
            }

            // Update max length (delete one element = one zero allowed)
            ans = max(ans, right - left);
        }

        return ans;
    }
};
