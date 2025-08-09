class Solution {
public:
    bool isPowerOfTwo(int n) {
        // A power of two must be > 0 and have only one '1' in its binary representation
        return n > 0 && (n & (n - 1)) == 0;
    }
};
