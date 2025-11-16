class Solution {
public:
    int numSub(string s) {
        const long long MOD = 1'000'000'007;
        long long count = 0;   // length of current consecutive '1' block
        long long ans = 0;

        for (char c : s) {
            if (c == '1') {
                count++;           // extend the current block
            } else {
                // close the block and add contribution
                ans = (ans + (count * (count + 1) / 2) % MOD) % MOD;
                count = 0;
            }
        }

        // add the final block if string ends with '1'
        ans = (ans + (count * (count + 1) / 2) % MOD) % MOD;

        return (int)ans;
    }
};
