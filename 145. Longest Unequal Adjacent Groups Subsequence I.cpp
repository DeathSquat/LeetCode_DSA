class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;
        int n = words.size();
        
        // Start by picking the first word
        result.push_back(words[0]);
        int lastGroup = groups[0];
        
        for (int i = 1; i < n; ++i) {
            // Pick the word if the group is different from the last picked group
            if (groups[i] != lastGroup) {
                result.push_back(words[i]);
                lastGroup = groups[i];
            }
        }
        
        return result;
    }
};
