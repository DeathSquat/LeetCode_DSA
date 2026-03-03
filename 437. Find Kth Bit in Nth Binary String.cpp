class Solution {
public:
    char findKthBit(int n, int k) {
        // Base case
        if (n == 1) return '0';
        
        int length = (1 << n) - 1;        // Length of Sn = 2^n - 1
        int mid = (length / 2) + 1;       // Middle position
        
        // If k is the middle element
        if (k == mid) return '1';
        
        // If k is in the first half
        if (k < mid)
            return findKthBit(n - 1, k);
        
        // If k is in the second half
        // Mirror position in first half
        char mirrored = findKthBit(n - 1, length - k + 1);
        
        // Invert the bit
        return (mirrored == '0') ? '1' : '0';
    }
};
