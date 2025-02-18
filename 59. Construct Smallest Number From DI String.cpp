class Solution {
public:
    string smallestNumber(string pattern) {
        string result;
        stack<int> st;
        
        for (int i = 0; i <= pattern.size(); i++) {
            st.push(i + 1);  // Push numbers from 1 to n+1
            
            // If the pattern is 'I' or it's the last iteration, pop the stack
            if (i == pattern.size() || pattern[i] == 'I') {
                while (!st.empty()) {
                    result += to_string(st.top());
                    st.pop();
                }
            }
        }
        
        return result;
    }
};
