class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Start from the last digit
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            // digit is 9, becomes 0 and carry continues
            digits[i] = 0;
        }
        
        // If we reach here, all digits were 9
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
