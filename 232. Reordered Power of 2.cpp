class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string target = sortDigits(n);
        
        // Check against all powers of 2 up to 1e9
        for (int i = 0; i < 31; ++i) {
            int power = 1 << i;
            if (sortDigits(power) == target) {
                return true;
            }
        }
        return false;
    }

private:
    string sortDigits(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        return s;
    }
};
