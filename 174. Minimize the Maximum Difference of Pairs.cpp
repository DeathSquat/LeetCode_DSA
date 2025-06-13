class Solution {
public:
    bool canFormPairs(vector<int>& nums, int maxDiff, int p) {
        int count = 0;
        for (int i = 1; i < nums.size(); ) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                count++;
                i += 2; // skip both indices to avoid reuse
            } else {
                i++;
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int low = 0, high = nums.back() - nums.front();
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canFormPairs(nums, mid, p)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
