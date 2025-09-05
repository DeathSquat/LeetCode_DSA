class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (long long k = 1; k <= 60; k++) {
            long long val = 1LL * num1 - 1LL * k * num2;
            if (val < 0) continue;
            int bits = __builtin_popcountll(val);
            if (bits <= k && k <= val) return k;
        }
        return -1;
    }
};
