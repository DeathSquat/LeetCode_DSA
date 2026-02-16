class Solution {
public:
    int reverseBits(int n) {
        unsigned int result = 0;
        
        for (int i = 0; i < 32; i++) {
            result <<= 1;          // Shift result to the left
            result |= (n & 1);     // Add the last bit of n
            n >>= 1;               // Shift n to the right
        }
        
        return result;
    }
};
