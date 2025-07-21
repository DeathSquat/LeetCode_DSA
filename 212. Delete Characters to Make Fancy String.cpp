class Solution {
public:
    string makeFancyString(string s) {
        string result;
        int count = 1;  // To keep track of consecutive characters

        result += s[0];  // Always include the first character

        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                count = 1;  // Reset count for a new character
            }

            if (count < 3) {
                result += s[i];
            }
        }

        return result;
    }
};
