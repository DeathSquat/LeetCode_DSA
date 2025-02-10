#include <stack>

class Solution {
public:
    string clearDigits(string s) {
        std::stack<char> st;
        
        for (char c : s) {
            if (isdigit(c)) {
                if (!st.empty()) {
                    st.pop();  // Remove the closest non-digit character to the left
                }
            } else {
                st.push(c);
            }
        }

        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
