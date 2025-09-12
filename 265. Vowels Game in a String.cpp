class Solution {
public:
    bool doesAliceWin(string s) {
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                return true; // Alice can always win if there's at least one vowel
            }
        }
        return false; // No vowels => Alice cannot make a move
    }
};
