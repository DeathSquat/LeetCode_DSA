class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long totalPeriods = 0;  // To store the total number of descent periods
        long long currentDescent = 1;  // Initial descent period count for the first day
        
        totalPeriods += currentDescent;  // The first day itself is a valid descent period
        
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] == prices[i - 1] - 1) {
                // Continuation of the descent period
                currentDescent += 1;
            } else {
                // A new descent period starts
                currentDescent = 1;
            }
            totalPeriods += currentDescent;  // Add the current descent periods
        }
        
        return totalPeriods;
    }
};
