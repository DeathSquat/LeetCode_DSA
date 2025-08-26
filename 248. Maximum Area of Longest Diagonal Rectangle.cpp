class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiagonal = 0.0;
        int maxArea = 0;

        for (auto &rect : dimensions) {
            int l = rect[0], w = rect[1];
            double diagonal = sqrt((double)l * l + (double)w * w);
            int area = l * w;

            if (diagonal > maxDiagonal) {
                maxDiagonal = diagonal;
                maxArea = area;
            } else if (fabs(diagonal - maxDiagonal) < 1e-9) { 
                // diagonals are equal (floating precision safe check)
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};
