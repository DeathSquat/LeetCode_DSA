class Solution {
public:
    int maxDifference(string s) {
        // Create a frequency map for characters
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        // Initialize max odd and min even frequencies
        int maxOdd = 0;
        int minEven = INT_MAX;
        
        // Iterate through frequency map
        for (auto& pair : freq) {
            int count = pair.second;
            if (count % 2 == 1) { // Odd frequency
                maxOdd = max(maxOdd, count);
            } else { // Even frequency
                minEven = min(minEven, count);
            }
        }
        
        // Return the maximum difference
        return maxOdd - minEven;
    }
};
