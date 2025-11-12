#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        for (int x : nums) {
            if (x == 1) ones++;
        }

        // Case 1: There are already some 1s
        if (ones > 0) {
            return n - ones;
        }

        // Case 2: Need to find smallest subarray with gcd == 1
        int minLen = n + 1;
        for (int i = 0; i < n; ++i) {
            int g = nums[i];
            for (int j = i + 1; j < n; ++j) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    minLen = min(minLen, j - i + 1);
                    break; // No need to continue extending this subarray
                }
            }
        }

        if (minLen == n + 1) return -1; // No gcd == 1 found
        return (minLen - 1) + (n - 1);
    }
};
