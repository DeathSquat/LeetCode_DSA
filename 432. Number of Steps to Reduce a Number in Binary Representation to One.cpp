class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;

        // Traverse from right to left (least significant bit to most)
        for (int i = s.length() - 1; i > 0; i--) {
            int bit = (s[i] - '0') + carry;

            if (bit == 1) {
                // odd → add 1 (creates carry), then divide
                steps += 2;
                carry = 1;
            } else {
                // even → just divide
                steps += 1;
                // carry remains the same
            }
        }

        // If there's still a carry at the highest bit
        return steps + carry;
    }
};
