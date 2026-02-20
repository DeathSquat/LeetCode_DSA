#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s.size() <= 2) return s;

        vector<string> parts;
        int balance = 0;
        int start = 0;

        // Split into top-level special substrings
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') balance++;
            else balance--;

            if (balance == 0) {
                // Recursively process inner substring
                string inner = s.substr(start + 1, i - start - 1);
                parts.push_back("1" + makeLargestSpecial(inner) + "0");
                start = i + 1;
            }
        }

        // Sort in descending lexicographical order
        sort(parts.begin(), parts.end(), greater<string>());

        // Concatenate result
        string result;
        for (const string &part : parts) {
            result += part;
        }

        return result;
    }
};
