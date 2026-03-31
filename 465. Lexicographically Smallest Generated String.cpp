class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int len = n + m - 1;
        
        string word(len, '?');
        
        // Step 1: Apply 'T' constraints
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?' || word[i + j] == str2[j]) {
                        word[i + j] = str2[j];
                    } else {
                        return ""; // conflict
                    }
                }
            }
        }
        
        // Helper to check if substring equals str2
        auto matches = [&](int start) {
            for (int j = 0; j < m; j++) {
                if (word[start + j] != str2[j]) return false;
            }
            return true;
        };
        
        // Step 2: Fill remaining '?' greedily
        for (int i = 0; i < len; i++) {
            if (word[i] == '?') {
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    
                    bool ok = true;
                    
                    // Only check affected substrings
                    for (int start = max(0, i - m + 1); start <= min(i, n - 1); start++) {
                        if (str1[start] == 'F' && matches(start)) {
                            ok = false;
                            break;
                        }
                    }
                    
                    if (ok) break;
                }
            }
        }
        
        // Step 3: Final validation for 'F'
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool equal = true;
                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        equal = false;
                        break;
                    }
                }
                if (equal) return "";
            }
        }
        
        return word;
    }
};
