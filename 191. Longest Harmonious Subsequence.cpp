class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        int longest = 0;

        // Count frequencies
        for (int num : nums) {
            freq[num]++;
        }

        // Check for neighbors
        for (auto& [key, val] : freq) {
            if (freq.count(key + 1)) {
                longest = max(longest, val + freq[key + 1]);
            }
        }

        return longest;
    }
};
