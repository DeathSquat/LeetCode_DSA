class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // If k is 1, the smallest number is 1 itself, and its length is 1
        if (k == 1) return 1;

        int remainder = 1 % k; // Start with the remainder for '1'
        int length = 1; // Length of the number (starting with '1')

        // A set to keep track of remainders we've seen to detect cycles
        unordered_set<int> remainders;
        
        while (remainder != 0) {
            // If we've already seen this remainder, we're stuck in a cycle
            if (remainders.find(remainder) != remainders.end()) {
                return -1;
            }

            // Add the remainder to the set
            remainders.insert(remainder);

            // Update the remainder to simulate adding another '1'
            remainder = (remainder * 10 + 1) % k;
            length++;
        }

        // If we exit the loop, we found the number whose length is `length`
        return length;
    }
};
