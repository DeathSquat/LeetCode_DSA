class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        // Put all nums into a hash set for O(1) lookup
        unordered_set<int> st(nums.begin(), nums.end());

        // Keep doubling as long as original exists in the set
        while (st.count(original)) {
            original *= 2;
        }

        return original;
    }
};
