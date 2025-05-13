class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> result;  // To store unique and sorted 3-digit even numbers
        
        int n = digits.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (i != j && j != k && i != k) {
                        int a = digits[i];
                        int b = digits[j];
                        int c = digits[k];
                        
                        if (a == 0) continue; // Skip if number starts with 0
                        if (c % 2 != 0) continue; // Last digit must be even
                        
                        int num = a * 100 + b * 10 + c;
                        result.insert(num);
                    }
                }
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};
