#include <unordered_map>
using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> groupSize;
        int maxSize = 0;

        for (int i = 1; i <= n; ++i) {
            int sum = digitSum(i);
            groupSize[sum]++;
            maxSize = max(maxSize, groupSize[sum]);
        }

        int count = 0;
        for (auto& [key, size] : groupSize) {
            if (size == maxSize) {
                count++;
            }
        }

        return count;
    }

private:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};
