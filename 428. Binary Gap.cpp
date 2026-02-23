class Solution {
public:
    int binaryGap(int n) {
        int last = -1;  // Last position of 1 we encountered
        int max_gap = 0;  // Maximum distance between two adjacent 1's
        
        // Iterate through the bits of n
        for (int i = 0; n > 0; ++i) {
            if (n & 1) {  // If the current bit is 1
                if (last != -1) {
                    max_gap = max(max_gap, i - last);  // Calculate the distance and update max_gap
                }
                last = i;  // Update the last position of 1
            }
            n >>= 1;  // Right shift n to process the next bit
        }
        
        return max_gap;
    }
};
