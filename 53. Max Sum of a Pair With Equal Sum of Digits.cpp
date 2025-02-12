#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> digitSumMap;
        int maxSum = -1;

        for (int num : nums) {
            int sumOfDigits = getDigitSum(num);
            if (digitSumMap.find(sumOfDigits) != digitSumMap.end()) {
                maxSum = max(maxSum, digitSumMap[sumOfDigits] + num);
                digitSumMap[sumOfDigits] = max(digitSumMap[sumOfDigits], num);
            } else {
                digitSumMap[sumOfDigits] = num;
            }
        }

        return maxSum;
    }

private:
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};
