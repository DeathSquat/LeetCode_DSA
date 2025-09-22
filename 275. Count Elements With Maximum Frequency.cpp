class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0, result = 0;

        // Count frequencies
        for (int num : nums) {
            freq[num]++;
            maxFreq = max(maxFreq, freq[num]);
        }

        // Count how many elements have max frequency
        for (auto& [key, val] : freq) {
            if (val == maxFreq) {
                result += val;
            }
        }

        return result;
    }
};
