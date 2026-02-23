class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        if (n < k) return false;

        // Set to store all unique substrings of length k
        unordered_set<string> substrings;

        // Iterate through the string and extract all substrings of length k
        for (int i = 0; i <= n - k; ++i) {
            substrings.insert(s.substr(i, k));
        }

        // Check if the number of substrings found equals the total number of possible binary codes of length k
        return substrings.size() == (1 << k);
    }
};
