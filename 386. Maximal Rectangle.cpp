class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> height(cols, 0);
        int maxArea = 0;
        
        for (int i = 0; i < rows; i++) {
            // Build histogram heights
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    height[j] += 1;
                else
                    height[j] = 0;
            }
            
            // Largest rectangle in histogram
            stack<int> st;
            for (int j = 0; j <= cols; j++) {
                int currHeight = (j == cols) ? 0 : height[j];
                while (!st.empty() && currHeight < height[st.top()]) {
                    int h = height[st.top()];
                    st.pop();
                    int w = st.empty() ? j : j - st.top() - 1;
                    maxArea = max(maxArea, h * w);
                }
                st.push(j);
            }
        }
        
        return maxArea;
    }
};
