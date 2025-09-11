#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        // Helper lambda to check if a character is a vowel
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                   c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
        };

        // Step 1: Extract all vowels
        vector<char> vowels;
        for (char c : s) {
            if (isVowel(c)) {
                vowels.push_back(c);
            }
        }

        // Step 2: Sort the vowels by ASCII value
        sort(vowels.begin(), vowels.end());

        // Step 3: Replace vowels in the original string in sorted order
        int idx = 0;
        for (char &c : s) {
            if (isVowel(c)) {
                c = vowels[idx++];
            }
        }

        return s;
    }
};
