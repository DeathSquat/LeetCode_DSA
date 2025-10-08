#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end()); // sort potions for binary search
        int m = potions.size();
        vector<int> result;

        for (int spell : spells) {
            // minimum potion strength required to reach 'success'
            long long required = (success + spell - 1) / spell; // ceil(success / spell)

            // find the first potion >= required using binary search
            auto it = lower_bound(potions.begin(), potions.end(), required);

            // number of potions that form successful pairs
            int count = potions.end() - it;
            result.push_back(count);
        }

        return result;
    }
};
