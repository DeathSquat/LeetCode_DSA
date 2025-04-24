#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> totalSet(nums.begin(), nums.end());
        int totalDistinct = totalSet.size();

        int result = 0;
        for (int i = 0; i < n; ++i) {
            unordered_set<int> currentSet;
            for (int j = i; j < n; ++j) {
                currentSet.insert(nums[j]);
                if (currentSet.size() == totalDistinct) {
                    result++;
                }
            }
        }
        return result;
    }
};
