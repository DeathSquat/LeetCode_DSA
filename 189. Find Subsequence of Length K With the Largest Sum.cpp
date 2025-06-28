class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // Pair each number with its index
        vector<pair<int, int>> indexedNums;
        for (int i = 0; i < nums.size(); ++i) {
            indexedNums.push_back({nums[i], i});
        }

        // Sort by value in descending order to pick k largest elements
        sort(indexedNums.begin(), indexedNums.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });

        // Take the first k elements
        vector<pair<int, int>> selected(indexedNums.begin(), indexedNums.begin() + k);

        // Sort the selected elements by their original indices to maintain order
        sort(selected.begin(), selected.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        // Extract the values for the final subsequence
        vector<int> result;
        for (auto &p : selected) {
            result.push_back(p.first);
        }

        return result;
    }
};
