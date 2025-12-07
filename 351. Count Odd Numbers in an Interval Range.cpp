class Solution {
public:
    int countOdds(int low, int high) {
        // If low is even, increment it to the next odd number
        if (low % 2 == 0) {
            low++;
        }
        
        // If high is even, decrement it to the previous odd number
        if (high % 2 == 0) {
            high--;
        }
        
        // If low > high, return 0 (no odd numbers in the range)
        if (low > high) {
            return 0;
        }
        
        // The number of odd numbers between low and high (inclusive) is:
        return (high - low) / 2 + 1;
    }
};
