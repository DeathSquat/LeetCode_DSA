class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();

        vector<int> first(26, -1), last(26, -1);

        // Record first and last appearance of each character
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        int ans = 0;

        // For each character as the outer character of palindrome
        for (int c = 0; c < 26; c++) {
            if (first[c] == -1 || first[c] == last[c]) continue;

            int L = first[c], R = last[c];

            // Count distinct characters between L and R
            unordered_set<char> mid;
            for (int i = L + 1; i < R; i++)
                mid.insert(s[i]);

            ans += mid.size();
        }

        return ans;
    }
};
