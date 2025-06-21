#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freqMap;
        for (char c : word) {
            freqMap[c]++;
        }

        vector<int> freqs;
        for (auto& p : freqMap) {
            freqs.push_back(p.second);
        }

        sort(freqs.begin(), freqs.end());
        int n = freqs.size();
        int total = word.size();
        int minDeletions = total;

        for (int i = 0; i < n; ++i) {
            int baseFreq = freqs[i];
            int deletions = 0;

            // Remove characters with frequency > baseFreq + k
            for (int j = i + 1; j < n; ++j) {
                if (freqs[j] > baseFreq + k) {
                    deletions += freqs[j] - (baseFreq + k);
                }
            }

            // Remove all characters with frequency < baseFreq
            for (int j = 0; j < i; ++j) {
                deletions += freqs[j];
            }

            minDeletions = min(minDeletions, deletions);
        }

        return minDeletions;
    }
};
