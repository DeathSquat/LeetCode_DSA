class Solution {
public:
    int minimumDeletions(string s) {
        int countB = 0;      // number of 'b's seen so far
        int deletions = 0;   // minimum deletions so far

        for (char c : s) {
            if (c == 'b') {
                countB++;
            } else { // c == 'a'
                deletions = min(deletions + 1, countB);
            }
        }
        return deletions;
    }
};
