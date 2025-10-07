#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1); // Default fill with 1 (for days with 0 rain)
        unordered_map<int, int> full; // lake -> last day it was filled
        set<int> dryDays; // stores indices of days we can dry (rains[i] == 0)

        for (int i = 0; i < n; ++i) {
            if (rains[i] == 0) {
                // store dry day index
                dryDays.insert(i);
            } else {
                int lake = rains[i];
                ans[i] = -1; // raining day -> always -1

                if (full.count(lake)) {
                    // This lake was already full, we must find a dry day after the last rain
                    auto it = dryDays.lower_bound(full[lake]); // find a dry day AFTER last time this lake got rain
                    if (it == dryDays.end()) {
                        // no available dry day -> flood unavoidable
                        return {};
                    }
                    int dryDay = *it;
                    ans[dryDay] = lake; // we dry this lake on that day
                    dryDays.erase(it); // remove that day since used
                }

                // mark this lake as full today
                full[lake] = i;
            }
        }

        return ans;
    }
};
