class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> wordCount;
        int length = 0;
        bool hasMiddle = false;

        // Count frequencies of each word
        for (const string& word : words) {
            wordCount[word]++;
        }

        for (auto& [word, count] : wordCount) {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (word != rev) {
                // Handle pairs like "ab" and "ba"
                if (wordCount.find(rev) != wordCount.end()) {
                    int pairCount = min(count, wordCount[rev]);
                    length += pairCount * 4;
                    wordCount[word] -= pairCount;
                    wordCount[rev] -= pairCount;
                }
            } else {
                // Handle words like "cc", "gg"
                int pairs = count / 2;
                length += pairs * 4;
                if (count % 2 == 1) {
                    hasMiddle = true;
                }
            }
        }

        if (hasMiddle) {
            length += 2;  // Add one middle word like "cc"
        }

        return length;
    }
};
