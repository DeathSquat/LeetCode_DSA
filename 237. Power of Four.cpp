class Solution {
public:
    bool isPowerOfFour(int n) {
        // A power of four must be positive
        if (n <= 0) return false;
        
        // Check if n is a power of two (only one bit set in binary)
        if ((n & (n - 1)) != 0) return false;
        
        // For a power of four, the single '1' bit should be in an odd position (0-based)
        // 0x55555555 = 01010101010101010101010101010101 in binary
        return (n & 0x55555555) != 0;
    }
};
