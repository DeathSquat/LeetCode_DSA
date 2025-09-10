class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        
        // Convert to sets for quick lookup
        vector<unordered_set<int>> lang(m + 1);
        for (int i = 0; i < m; i++) {
            for (int l : languages[i]) {
                lang[i + 1].insert(l);
            }
        }
        
        // Find problematic friendships
        unordered_set<int> problematicUsers;
        for (auto& f : friendships) {
            int u = f[0], v = f[1];
            bool canCommunicate = false;
            for (int l : lang[u]) {
                if (lang[v].count(l)) {
                    canCommunicate = true;
                    break;
                }
            }
            if (!canCommunicate) {
                problematicUsers.insert(u);
                problematicUsers.insert(v);
            }
        }
        
        if (problematicUsers.empty()) return 0; // Already all connected
        
        int ans = INT_MAX;
        
        // Try teaching each language
        for (int L = 1; L <= n; L++) {
            int count = 0;
            for (int user : problematicUsers) {
                if (!lang[user].count(L)) {
                    count++;
                }
            }
            ans = min(ans, count);
        }
        
        return ans;
    }
};
