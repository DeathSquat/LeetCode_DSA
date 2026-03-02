class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> trailingZeros(n);
        
        // Count trailing zeros for each row
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) count++;
                else break;
            }
            trailingZeros[i] = count;
        }
        
        int swaps = 0;
        
        // Try to place correct row at each position
        for (int i = 0; i < n; i++) {
            int required = n - 1 - i;
            int j = i;
            
            // Find a row that satisfies requirement
            while (j < n && trailingZeros[j] < required) {
                j++;
            }
            
            // If not found
            if (j == n) return -1;
            
            // Bring row j up to position i
            while (j > i) {
                swap(trailingZeros[j], trailingZeros[j - 1]);
                swaps++;
                j--;
            }
        }
        
        return swaps;
    }
};
