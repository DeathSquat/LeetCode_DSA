class Solution {
public:
    bool isValid(int num, int square, int target) {
        string s = to_string(square);
        return canPartition(s, 0, target);
    }

    bool canPartition(string &s, int index, int target) {
        if (index == s.size()) return target == 0;
        int sum = 0;
        for (int i = index; i < s.size(); ++i) {
            sum = sum * 10 + (s[i] - '0');
            if (sum > target) break;  // No need to check further
            if (canPartition(s, i + 1, target - sum)) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int result = 0;
        for (int i = 1; i <= n; ++i) {
            int square = i * i;
            if (isValid(i, square, i)) {
                result += square;
            }
        }
        return result;
    }
};
