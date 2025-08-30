class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Arrays of hash sets to track numbers in rows, cols, and boxes
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue; // Skip empty cells

                // Check row
                if (rows[i].count(c)) return false;
                rows[i].insert(c);

                // Check column
                if (cols[j].count(c)) return false;
                cols[j].insert(c);

                // Check 3x3 sub-box
                int boxIndex = (i / 3) * 3 + (j / 3);
                if (boxes[boxIndex].count(c)) return false;
                boxes[boxIndex].insert(c);
            }
        }
        return true;
    }
};
