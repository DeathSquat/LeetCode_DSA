#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int maxSum = 0, currentSum = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (seen.count(nums[right])) {
                seen.erase(nums[left]);
                currentSum -= nums[left];
                ++left;
            }
            seen.insert(nums[right]);
            currentSum += nums[right];
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};
