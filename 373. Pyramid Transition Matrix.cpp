class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_set<string> bad;  // memo for impossible states

    bool dfs(string bottom) {
        if (bottom.size() == 1) return true;
        if (bad.count(bottom)) return false;

        vector<string> nextRows;
        buildNext(bottom, 0, "", nextRows);

        for (auto &row : nextRows) {
            if (dfs(row)) return true;
        }

        bad.insert(bottom);
        return false;
    }

    void buildNext(const string &bottom, int idx, string curr, vector<string> &res) {
        if (idx == bottom.size() - 1) {
            res.push_back(curr);
            return;
        }

        string key = bottom.substr(idx, 2);
        if (!mp.count(key)) return;

        for (char c : mp[key]) {
            buildNext(bottom, idx + 1, curr + c, res);
        }
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        return dfs(bottom);
    }
};
