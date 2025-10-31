class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 0); // to count frequency of each number
        vector<int> result;

        for (int num : nums) {
            count[num]++;
            if (count[num] == 2) { // found a repeated number
                result.push_back(num);
            }
        }
        return result; // contains exactly 2 sneaky numbers
    }
};
