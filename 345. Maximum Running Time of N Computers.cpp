class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long totalBatteryTime = 0;
        for (int i = 0; i < batteries.size(); i++) {
            totalBatteryTime += batteries[i];
        }

        // Binary search for the maximum time T
        long long left = 0, right = totalBatteryTime / n;
        
        while (left < right) {
            long long mid = left + (right - left + 1) / 2;
            long long totalTimeAvailable = 0;
            
            // Calculate the total available time from all batteries
            for (int i = 0; i < batteries.size(); i++) {
                totalTimeAvailable += min((long long)batteries[i], mid);
            }

            // Check if we can run all n computers for `mid` minutes
            if (totalTimeAvailable >= mid * n) {
                left = mid; // We can run for `mid` minutes, so try longer
            } else {
                right = mid - 1; // We cannot run for `mid` minutes, try shorter
            }
        }
        
        return left;
    }
};
