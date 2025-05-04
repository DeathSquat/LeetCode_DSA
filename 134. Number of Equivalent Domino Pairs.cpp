class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        // Array to store count of each normalized domino key
        int count[100] = {0};
        int result = 0;

        for (auto& d : dominoes) {
            // Normalize the domino (a,b) -> (min(a,b)*10 + max(a,b))
            int key = d[0] < d[1] ? d[0] * 10 + d[1] : d[1] * 10 + d[0];
            result += count[key];  // Every previous occurrence of this key can pair with current one
            count[key]++;
        }

        return result;
    }
};
