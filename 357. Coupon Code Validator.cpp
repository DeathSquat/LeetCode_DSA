class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map<string, vector<string>> buckets;
        unordered_set<string> validLines = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };

        auto isValidCode = [](const string& s) {
            if (s.empty()) return false;
            for (char c : s) {
                if (!isalnum(c) && c != '_') return false;
            }
            return true;
        };

        int n = code.size();
        for (int i = 0; i < n; i++) {
            if (!isActive[i]) continue;
            if (!isValidCode(code[i])) continue;
            if (validLines.count(businessLine[i]) == 0) continue;

            buckets[businessLine[i]].push_back(code[i]);
        }

        vector<string> order = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };

        vector<string> result;
        for (const string& line : order) {
            if (buckets.count(line)) {
                auto& v = buckets[line];
                sort(v.begin(), v.end());
                result.insert(result.end(), v.begin(), v.end());
            }
        }

        return result;
    }
};
