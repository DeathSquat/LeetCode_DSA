class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;

        while (i < n - 1) {       // stop before the last bit
            if (bits[i] == 1) {
                i += 2;           // two-bit character: 10 or 11
            } else {
                i += 1;           // one-bit character: 0
            }
        }

        // If we end exactly at the last position, last char is 1-bit
        return i == n - 1;
    }
};
