#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        
        // This will store the previous word's sorted version
        string prevSorted = "";
        
        for (const string& word : words) {
            string sortedWord = word;
            // Sort the current word to get a standard form for comparison
            sort(sortedWord.begin(), sortedWord.end());
            
            // If the sorted word is not the same as the previous one, add it to the result
            if (sortedWord != prevSorted) {
                result.push_back(word);
            }
            
            // Update the previous sorted word for the next iteration
            prevSorted = sortedWord;
        }
        
        return result;
    }
};
