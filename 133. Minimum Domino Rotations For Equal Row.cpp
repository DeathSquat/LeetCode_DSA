class Solution {
public:
    int check(int target, vector<int>& tops, vector<int>& bottoms) {
        int rotationsTop = 0;
        int rotationsBottom = 0;
        int n = tops.size();
        for (int i = 0; i < n; ++i) {
            if (tops[i] != target && bottoms[i] != target) {
                return -1; // Not possible to make this value uniform
            } else if (tops[i] != target) {
                rotationsTop++; // Need to rotate top to get target
            } else if (bottoms[i] != target) {
                rotationsBottom++; // Need to rotate bottom to get target
            }
        }
        return min(rotationsTop, rotationsBottom);
    }
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = check(tops[0], tops, bottoms);
        if (result != -1) return result;
        return check(bottoms[0], tops, bottoms);
    }
};
