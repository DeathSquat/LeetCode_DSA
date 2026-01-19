class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Prefix sum matrix (1-based indexing)
        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pref[i][j] = mat[i - 1][j - 1]
                           + pref[i - 1][j]
                           + pref[i][j - 1]
                           - pref[i - 1][j - 1];
            }
        }
        
        auto existsSquare = [&](int len) {
            for (int i = len; i <= m; i++) {
                for (int j = len; j <= n; j++) {
                    int sum = pref[i][j]
                            - pref[i - len][j]
                            - pref[i][j - len]
                            + pref[i - len][j - len];
                    if (sum <= threshold) return true;
                }
            }
            return false;
        };
        
        int left = 0, right = min(m, n);
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (existsSquare(mid))
                left = mid;
            else
                right = mid - 1;
        }
        
        return left;
    }
};
