class Solution {
public:
    int smallestNumber(int n) {
        while (true) {
            // Check if the current number n has all set bits
            if ((n & (n + 1)) == 0) {
                return n;
            }
            // If not, increment n and check again
            n++;
        }
    }
};
