class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        // Step 1: map value -> indices
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<int> ans;
        
        // Step 2: process queries
        for (int q : queries) {
            int val = nums[q];
            auto &v = mp[val];
            
            // If only one occurrence
            if (v.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            
            // Binary search
            int pos = lower_bound(v.begin(), v.end(), q) - v.begin();
            
            int res = INT_MAX;
            
            // Check next
            int next = v[(pos + 1) % v.size()];
            int dist1 = abs(q - next);
            dist1 = min(dist1, n - dist1);
            res = min(res, dist1);
            
            // Check previous
            int prev = v[(pos - 1 + v.size()) % v.size()];
            int dist2 = abs(q - prev);
            dist2 = min(dist2, n - dist2);
            res = min(res, dist2);
            
            ans.push_back(res);
        }
        
        return ans;
    }
};
