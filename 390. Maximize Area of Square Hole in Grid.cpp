class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        auto longestConsecutive = [](vector<int>& bars) {
            sort(bars.begin(), bars.end());
            int best = 1, cur = 1;
            for (int i = 1; i < bars.size(); i++) {
                if (bars[i] == bars[i - 1] + 1) {
                    cur++;
                } else {
                    cur = 1;
                }
                best = max(best, cur);
            }
            return best + 1;  // k bars removed → k+1 cells
        };

        int maxHeight = longestConsecutive(hBars);
        int maxWidth  = longestConsecutive(vBars);

        int side = min(maxHeight, maxWidth);
        return side * side;
    }
};
