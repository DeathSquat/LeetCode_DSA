class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26, 0);  // Count frequency of characters in s
        for (char c : s) {
            freq[c - 'a']++;
        }

        string result = "";
        stack<char> t;  // Robot’s internal string

        char minChar = 'a';  // Current minimum character we are looking for

        for (char c : s) {
            t.push(c);
            freq[c - 'a']--;

            // Move minChar to the smallest remaining character in s
            while (minChar <= 'z' && freq[minChar - 'a'] == 0) {
                minChar++;
            }

            // Pop from stack t to result if top is <= minChar
            while (!t.empty() && t.top() <= minChar) {
                result += t.top();
                t.pop();
            }
        }

        // Pop remaining characters from the stack
        while (!t.empty()) {
            result += t.top();
            t.pop();
        }

        return result;
    }
};
