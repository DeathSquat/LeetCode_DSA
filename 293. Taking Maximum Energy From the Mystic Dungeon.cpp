class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n, INT_MIN);  // Initialize dp array with a very small value
        
        // Base case: The last magician's energy
        dp[n - 1] = energy[n - 1];
        
        // Fill dp array in reverse order
        for (int i = n - 2; i >= 0; --i) {
            // We can only jump to i + k if it's within bounds
            if (i + k < n) {
                dp[i] = energy[i] + dp[i + k];
            } else {
                dp[i] = energy[i];
            }
        }
        
        // The result is the maximum energy from any starting point
        return *max_element(dp.begin(), dp.end());
    }
};
