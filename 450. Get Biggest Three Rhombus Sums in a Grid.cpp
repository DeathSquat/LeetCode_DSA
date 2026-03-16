class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        set<int, greater<int>> st;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                // size = 0 rhombus
                st.insert(grid[i][j]);
                
                for(int k = 1; ; k++){
                    
                    int r = i + 2*k;
                    int c1 = j - k;
                    int c2 = j + k;
                    
                    if(r >= m || c1 < 0 || c2 >= n) break;
                    
                    int sum = 0;
                    
                    int x = i, y = j;
                    
                    // top -> right
                    for(int t = 0; t < k; t++){
                        sum += grid[x+t][y+t];
                    }
                    
                    // right -> bottom
                    for(int t = 0; t < k; t++){
                        sum += grid[x+k+t][y+k-t];
                    }
                    
                    // bottom -> left
                    for(int t = 0; t < k; t++){
                        sum += grid[x+2*k-t][y-t];
                    }
                    
                    // left -> top
                    for(int t = 0; t < k; t++){
                        sum += grid[x+k-t][y-k+t];
                    }
                    
                    st.insert(sum);
                }
            }
        }
        
        vector<int> ans;
        for(int v : st){
            ans.push_back(v);
            if(ans.size() == 3) break;
        }
        
        return ans;
    }
};
