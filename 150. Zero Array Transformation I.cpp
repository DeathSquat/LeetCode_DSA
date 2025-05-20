class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> count(n + 1, 0); // difference array for range frequency

        // Step 1: Build frequency coverage of each index via difference array
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            count[l] += 1;
            if (r + 1 < n) {
                count[r + 1] -= 1;
            }
        }

        // Step 2: Accumulate to get final number of times each index is covered
        for (int i = 1; i < n; ++i) {
            count[i] += count[i - 1];
        }

        // Step 3: Check if each nums[i] can be reduced to 0 with available operations
        for (int i = 0; i < n; ++i) {
            if (nums[i] > count[i]) {
                return false; // Not enough operations to reduce nums[i] to 0
            }
        }

        return true;
    }
};
