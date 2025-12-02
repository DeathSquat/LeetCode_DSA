class Solution {
public:
    static const long long MOD = 1000000007;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<long long, long long> countY;

        // Count how many points exist on each y coordinate
        for (auto &p : points) {
            countY[p[1]]++;
        }

        vector<long long> seg; 
        seg.reserve(countY.size());

        // For each y, compute C(k,2)
        for (auto &kv : countY) {
            long long k = kv.second;
            if (k >= 2) {
                long long s = (k * (k - 1) / 2) % MOD;
                seg.push_back(s);
            }
        }

        // Sum over all pairs s[i] * s[j] using prefix sum
        long long total = 0;
        long long prefix = 0;

        for (long long x : seg) {
            total = (total + prefix * x) % MOD;
            prefix = (prefix + x) % MOD;
        }

        return total;
    }
};
