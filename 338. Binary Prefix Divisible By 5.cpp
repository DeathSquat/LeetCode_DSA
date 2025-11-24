class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;
        result.reserve(nums.size());
        
        int mod = 0;  // store current value % 5
        
        for (int b : nums) {
            mod = (mod * 2 + b) % 5;
            result.push_back(mod == 0);
        }
        
        return result;
    }
};
