class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        
        for (int n : nums) {
            // If n is even, no solution exists
            if ((n & 1) == 0) {
                ans.push_back(-1);
                continue;
            }
            
            // Count trailing ones
            int t = 0;
            int temp = n;
            while (temp & 1) {
                t++;
                temp >>= 1;
            }
            
            // Minimum x
            int x = n - (1 << (t - 1));
            ans.push_back(x);
        }
        
        return ans;
    }
};
