class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string result = dominoes;
        int i = 0;

        // Add sentinels to handle edge cases easily
        result = 'L' + result + 'R';
        n += 2;

        int left = 0;
        for (int right = 1; right < n; ++right) {
            if (result[right] == '.') continue;

            if (result[left] == result[right]) {
                // Both are same (e.g., 'R...R' or 'L...L')
                for (int k = left + 1; k < right; ++k)
                    result[k] = result[left];
            } else if (result[left] == 'R' && result[right] == 'L') {
                // One is R and the other is L (e.g., 'R...L')
                int l = left + 1, r = right - 1;
                while (l < r) {
                    result[l++] = 'R';
                    result[r--] = 'L';
                }
            }
            // else 'L...R' stays as is
            left = right;
        }

        // Remove sentinels before returning
        return result.substr(1, n - 2);
    }
};
