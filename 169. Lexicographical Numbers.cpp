class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int current = 1;
        for (int i = 0; i < n; ++i) {
            result.push_back(current);
            if (current * 10 <= n) {
                current *= 10;  // Go deeper in lexicographical tree
            } else {
                while (current % 10 == 9 || current + 1 > n) {
                    current /= 10;  // Go back up
                }
                ++current;  // Move to next node
            }
        }
        return result;
    }
};
