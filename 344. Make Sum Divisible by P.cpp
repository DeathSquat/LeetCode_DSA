class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums) total += x;
        int rem = total % p;
        if (rem == 0) return 0;  // already divisible
        
        unordered_map<int, int> mp;
        mp[0] = -1; // prefix before the array starts
        
        long long prefix = 0;
        int res = nums.size();
        
        for (int i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i]) % p;
            int target = (prefix - rem + p) % p;
            
            if (mp.count(target)) {
                res = min(res, i - mp[target]);
            }
            
            // store latest index of this prefix mod
            mp[prefix] = i;
        }
        
        return (res == nums.size() ? -1 : res);
    }
};
