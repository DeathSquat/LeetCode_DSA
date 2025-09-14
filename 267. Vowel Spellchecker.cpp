class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelInsensitive;
        
        auto devowel = [](string s) {
            for (auto &c : s) {
                if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') c = '*';
            }
            return s;
        };
        
        for (auto &w : wordlist) {
            string lower = w;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            if (!caseInsensitive.count(lower)) caseInsensitive[lower] = w;
            string vlow = devowel(lower);
            if (!vowelInsensitive.count(vlow)) vowelInsensitive[vlow] = w;
        }
        
        vector<string> ans;
        for (auto &q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }
            string lower = q;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            if (caseInsensitive.count(lower)) {
                ans.push_back(caseInsensitive[lower]);
                continue;
            }
            string vlow = devowel(lower);
            if (vowelInsensitive.count(vlow)) {
                ans.push_back(vowelInsensitive[vlow]);
                continue;
            }
            ans.push_back("");
        }
        
        return ans;
    }
};
