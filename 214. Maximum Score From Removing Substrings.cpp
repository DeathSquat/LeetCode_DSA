class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x < y) {
            swap(x, y);
            reverse(s.begin(), s.end());
        }

        int total = 0;
        stack<char> st;

        // First, remove all "ab" substrings (or "ba" if y > x originally)
        for (char c : s) {
            if (!st.empty() && st.top() == 'a' && c == 'b') {
                st.pop();
                total += x;
            } else {
                st.push(c);
            }
        }

        // Now we process the remaining string to remove the other pattern
        string remaining;
        while (!st.empty()) {
            remaining += st.top();
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());

        // Remove all "ba" substrings now
        for (char c : remaining) {
            if (!st.empty() && st.top() == 'b' && c == 'a') {
                st.pop();
                total += y;
            } else {
                st.push(c);
            }
        }

        return total;
    }
};
