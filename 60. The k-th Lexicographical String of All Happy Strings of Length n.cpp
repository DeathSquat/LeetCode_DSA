class Solution {
public:
    void generateHappyStrings(int n, string &current, vector<string> &happyStrings) {
        if (current.size() == n) {
            happyStrings.push_back(current);
            return;
        }
        
        for (char ch : {'a', 'b', 'c'}) {
            if (current.empty() || current.back() != ch) {  // Ensure no consecutive same characters
                current.push_back(ch);
                generateHappyStrings(n, current, happyStrings);
                current.pop_back();  // Backtrack
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> happyStrings;
        string current;
        
        generateHappyStrings(n, current, happyStrings);
        
        if (k > happyStrings.size()) return "";  // If k is out of range, return empty string
        return happyStrings[k - 1];  // k is 1-based index
    }
};
