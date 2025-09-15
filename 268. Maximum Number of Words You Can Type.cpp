class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        // Put all broken letters into a set for quick lookup
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        
        int count = 0;  // to count valid words
        bool valid = true;
        
        for (int i = 0; i <= text.size(); i++) {
            if (i == text.size() || text[i] == ' ') {
                if (valid) count++;  // if word had no broken letter
                valid = true;        // reset for next word
            } else {
                if (broken.count(text[i])) {
                    valid = false;   // word cannot be typed
                }
            }
        }
        
        return count;
    }
};
