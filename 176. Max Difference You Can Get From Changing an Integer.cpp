class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        // Create the maximum number by replacing a digit with 9
        string maxStr = s;
        for (char c : s) {
            if (c != '9') {
                for (char& ch : maxStr) {
                    if (ch == c) ch = '9';
                }
                break;
            }
        }

        // Create the minimum number by replacing a digit with either 1 or 0
        string minStr = s;
        if (s[0] != '1') {
            // replace the first digit (non-1) with 1 to avoid leading zero
            char target = s[0];
            for (char& ch : minStr) {
                if (ch == target) ch = '1';
            }
        } else {
            // replace any other digit (not 0 or 1) with 0
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    char target = s[i];
                    for (char& ch : minStr) {
                        if (ch == target) ch = '0';
                    }
                    break;
                }
            }
        }

        int maxNum = stoi(maxStr);
        int minNum = stoi(minStr);

        return maxNum - minNum;
    }
};
