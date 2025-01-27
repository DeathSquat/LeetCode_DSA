class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Initialize a 2D matrix to represent if a course is a prerequisite of another
        vector<vector<bool>> isPrerequisite(numCourses, vector<bool>(numCourses, false));
        
        // Set direct prerequisites
        for (const auto& pre : prerequisites) {
            isPrerequisite[pre[0]][pre[1]] = true;
        }
        
        // Floyd-Warshall Algorithm to compute transitive closure
        for (int k = 0; k < numCourses; ++k) {
            for (int i = 0; i < numCourses; ++i) {
                for (int j = 0; j < numCourses; ++j) {
                    isPrerequisite[i][j] = isPrerequisite[i][j] || 
                                           (isPrerequisite[i][k] && isPrerequisite[k][j]);
                }
            }
        }
        
        // Answer queries
        vector<bool> result;
        for (const auto& query : queries) {
            result.push_back(isPrerequisite[query[0]][query[1]]);
        }
        
        return result;
    }
};
