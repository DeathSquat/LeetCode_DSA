class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSet(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        // Always keep the smaller character as the root
        if (px < py)
            parent[py] = px;
        else
            parent[px] = py;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        // Initially, each character is its own parent
        for (int i = 0; i < 26; ++i) {
            parent[i] = i;
        }

        // Union the characters in s1 and s2
        for (int i = 0; i < s1.size(); ++i) {
            unionSet(s1[i] - 'a', s2[i] - 'a');
        }

        // Build the result by finding the smallest equivalent character
        string result;
        for (char ch : baseStr) {
            int smallest = find(ch - 'a');
            result += (char)(smallest + 'a');
        }

        return result;
    }
};
