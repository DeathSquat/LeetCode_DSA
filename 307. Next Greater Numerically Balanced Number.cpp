class Solution {
public:
    // Function to check if a number is numerically balanced
    bool isBalanced(int num) {
        string s = to_string(num);
        vector<int> count(10, 0);
        for (char c : s) count[c - '0']++;
        
        for (int d = 0; d <= 9; ++d) {
            if (count[d] != 0 && count[d] != d) return false;
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        for (int i = n + 1; ; ++i) {
            if (isBalanced(i)) return i;
        }
    }
};
