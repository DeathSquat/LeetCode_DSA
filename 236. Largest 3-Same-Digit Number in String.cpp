class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for (int i = 0; i + 2 < num.size(); i++) {
            // Check if current 3 characters are the same
            if (num[i] == num[i+1] && num[i+1] == num[i+2]) {
                string curr = num.substr(i, 3);
                if (ans.empty() || curr > ans) {
                    ans = curr;
                }
            }
        }
        return ans;
    }
};
