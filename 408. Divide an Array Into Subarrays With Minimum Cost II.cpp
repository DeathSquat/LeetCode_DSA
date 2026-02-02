class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        multiset<long long> small, large;
        long long sumSmall = 0;
        long long ans = LLONG_MAX;

        auto add = [&](long long x) {
            if ((int)small.size() < k - 1) {
                small.insert(x);
                sumSmall += x;
            } else {
                auto it = prev(small.end());
                if (x < *it) {
                    sumSmall -= *it;
                    large.insert(*it);
                    small.erase(it);
                    small.insert(x);
                    sumSmall += x;
                } else {
                    large.insert(x);
                }
            }
        };

        auto remove = [&](long long x) {
            auto itSmall = small.find(x);
            if (itSmall != small.end()) {
                sumSmall -= x;
                small.erase(itSmall);
                if (!large.empty()) {
                    auto it = large.begin();
                    small.insert(*it);
                    sumSmall += *it;
                    large.erase(it);
                }
            } else {
                large.erase(large.find(x));
            }
        };

        int left = 1;
        for (int right = 1; right < n; right++) {
            add(nums[right]);

            if (right - left + 1 > dist + 1) {
                remove(nums[left]);
                left++;
            }

            if ((int)small.size() == k - 1) {
                ans = min(ans, nums[0] + sumSmall);
            }
        }

        return ans;
    }
};
