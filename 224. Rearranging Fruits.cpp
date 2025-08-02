class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> count;

        for (int fruit : basket1) count[fruit]++;
        for (int fruit : basket2) count[fruit]--;

        vector<int> excess;

        for (auto &[fruit, freq] : count) {
            if (freq % 2 != 0) return -1;  // Impossible to balance
            for (int i = 0; i < abs(freq) / 2; ++i)
                excess.push_back(fruit);
        }

        if (excess.empty()) return 0;

        sort(excess.begin(), excess.end());
        int minElement = min(*min_element(basket1.begin(), basket1.end()),
                             *min_element(basket2.begin(), basket2.end()));

        long long cost = 0;
        int n = excess.size();
        for (int i = 0; i < n / 2; ++i) {
            cost += min(2LL * minElement, 1LL * excess[i]);
        }

        return cost;
    }
};
