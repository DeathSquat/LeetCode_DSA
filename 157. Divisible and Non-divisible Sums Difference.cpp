class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0, num2 = 0;
        for (int i = 1; i <= n; ++i) {
            if (i % m == 0) {
                num2 += i;  // Sum of divisible by m
            } else {
                num1 += i;  // Sum of not divisible by m
            }
        }
        return num1 - num2;
    }
};
