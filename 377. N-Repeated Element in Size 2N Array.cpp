class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> freq_map;
        
        // Iterate through the array and count frequencies
        for (int num : nums) {
            freq_map[num]++;
            // If any number reaches n occurrences, return it
            if (freq_map[num] == nums.size() / 2) {
                return num;
            }
        }
        
        return -1; // In case of no repeated element (shouldn't reach here as per problem statement)
    }
};
