class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        
        // Store indices for each value
        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]].push_back(i);
        }
        
        int ans = INT_MAX;
        
        // Process each value
        for (auto& [val, indices] : pos) {
            if (indices.size() < 3) continue;
            
            // Check consecutive triplets
            for (int i = 0; i + 2 < indices.size(); i++) {
                int first = indices[i];
                int third = indices[i + 2];
                
                int dist = 2 * (third - first);
                ans = min(ans, dist);
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};
