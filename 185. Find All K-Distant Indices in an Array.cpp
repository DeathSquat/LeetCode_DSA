class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> result;
        
        // Traverse the array and for every key occurrence,
        // mark indices in range [index-k, index+k]
        vector<bool> isKDist(n, false);

        for (int i = 0; i < n; ++i) {
            if (nums[i] == key) {
                int left = max(0, i - k);
                int right = min(n - 1, i + k);
                for (int j = left; j <= right; ++j) {
                    isKDist[j] = true;
                }
            }
        }

        // Collect all indices marked as true
        for (int i = 0; i < n; ++i) {
            if (isKDist[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};
