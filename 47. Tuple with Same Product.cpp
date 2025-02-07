#include <unordered_map>
#include <vector>

class Solution {
public:
    int tupleSameProduct(std::vector<int>& nums) {
        std::unordered_map<int, int> productCount;
        int count = 0;

        // Calculate all possible products a * b and store in hashmap
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                productCount[product]++;
            }
        }

        // Count the valid tuples
        for (const auto& pair : productCount) {
            int freq = pair.second;
            if (freq > 1) {
                count += (freq * (freq - 1) / 2) * 8; // Each pair can be arranged in 8 ways
            }
        }

        return count;
    }
};
