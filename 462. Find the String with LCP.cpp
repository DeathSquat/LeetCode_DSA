class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        
        // Step 1: Basic validation
        for (int i = 0; i < n; i++) {
            if (lcp[i][i] != n - i) return "";
            for (int j = 0; j < n; j++) {
                if (lcp[i][j] != lcp[j][i]) return "";
            }
        }

        // Step 2: Build string
        string word(n, '?');
        char cur = 'a';

        for (int i = 0; i < n; i++) {
            if (word[i] != '?') continue;

            if (cur > 'z') return ""; // only 26 letters allowed

            for (int j = i; j < n; j++) {
                if (lcp[i][j] > 0) {
                    word[j] = cur;
                }
            }
            cur++;
        }

        // Step 3: Validate by recomputing LCP
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word[i] == word[j]) {
                    if (i + 1 < n && j + 1 < n)
                        dp[i][j] = 1 + dp[i + 1][j + 1];
                    else
                        dp[i][j] = 1;
                }
            }
        }

        // Step 4: Compare with input
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] != lcp[i][j]) return "";
            }
        }

        return word;
    }
};
