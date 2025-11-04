#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> result;
        int n = nums.size();
        
        // Helper function to calculate X-Sum for a given subarray
        auto calculateXSum = [](unordered_map<int, int>& freqMap, int x) {
            // Create a vector of pairs (element, frequency)
            vector<pair<int, int>> freqVec(freqMap.begin(), freqMap.end());
            // Sort by frequency (desc), and by value (desc) if frequencies are the same
            sort(freqVec.begin(), freqVec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                if (a.second == b.second)
                    return a.first > b.first;
                return a.second > b.second;
            });
            
            // Sum the top X frequent elements
            int sum = 0;
            for (int i = 0; i < min(x, (int)freqVec.size()); ++i) {
                sum += freqVec[i].first * freqVec[i].second;
            }
            return sum;
        };
        
        // Initialize the frequency map for the first subarray
        unordered_map<int, int> freqMap;
        for (int i = 0; i < k; ++i) {
            freqMap[nums[i]]++;
        }
        
        // Calculate the X-Sum for the first subarray
        result.push_back(calculateXSum(freqMap, x));
        
        // Slide the window and update the frequency map
        for (int i = 1; i <= n - k; ++i) {
            // Remove the element going out of the window
            freqMap[nums[i - 1]]--;
            if (freqMap[nums[i - 1]] == 0) {
                freqMap.erase(nums[i - 1]);
            }
            // Add the new element coming into the window
            freqMap[nums[i + k - 1]]++;
            
            // Calculate the X-Sum for the current window
            result.push_back(calculateXSum(freqMap, x));
        }
        
        return result;
    }
};
