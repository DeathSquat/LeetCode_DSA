class Solution {
public:
    bool hasSameDigits(string s) {
        // Continue performing operations until only 2 digits remain
        while (s.size() > 2) {
            string next = "";
            for (int i = 0; i + 1 < s.size(); i++) {
                int d1 = s[i] - '0';
                int d2 = s[i + 1] - '0';
                int newDigit = (d1 + d2) % 10;
                next.push_back('0' + newDigit);
            }
            s = next;
        }
        // Return true if both digits are equal
        return s[0] == s[1];
    }
};
