class Solution {
public:
    const int MOD = 1e9 + 7;
    const int MAX = 10000;
    vector<int> spf;

    Solution() {
        // Smallest Prime Factor sieve
        spf.resize(MAX + 1);
        for (int i = 2; i <= MAX; ++i) spf[i] = i;
        for (int i = 2; i * i <= MAX; ++i) {
            if (spf[i] == i) {
                for (int j = i * i; j <= MAX; j += i)
                    if (spf[j] == j) spf[j] = i;
            }
        }
    }

    long long modpow(long long a, long long b, long long mod) {
        long long res = 1;
        while (b > 0) {
            if (b % 2) res = res * a % mod;
            a = a * a % mod;
            b /= 2;
        }
        return res;
    }

    long long modinv(long long a) {
        return modpow(a, MOD - 2, MOD);
    }

    vector<long long> fac, inv;

    void prepareFactorials(int n) {
        fac.resize(n + 1);
        inv.resize(n + 1);
        fac[0] = 1;
        for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % MOD;
        inv[n] = modinv(fac[n]);
        for (int i = n - 1; i >= 0; --i) inv[i] = inv[i + 1] * (i + 1) % MOD;
    }

    long long nCr(int n, int r) {
        if (n < r) return 0;
        return fac[n] * inv[r] % MOD * inv[n - r] % MOD;
    }

    unordered_map<int, int> primeFactorize(int x) {
        unordered_map<int, int> factors;
        while (x > 1) {
            int p = spf[x];
            factors[p]++;
            x /= p;
        }
        return factors;
    }

    int idealArrays(int n, int maxValue) {
        prepareFactorials(n + MAX);  // safe upper bound
        long long res = 0;

        for (int num = 1; num <= maxValue; ++num) {
            auto factors = primeFactorize(num);
            long long ways = 1;
            for (auto &[prime, freq] : factors) {
                ways = ways * nCr(n - 1 + freq, freq) % MOD;
            }
            res = (res + ways) % MOD;
        }

        return (int)res;
    }
};
