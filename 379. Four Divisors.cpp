#include <vector>
#include <cmath>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        // Maximum value for nums[i]
        const int MAX = 100000;
        
        // Step 1: Sieve of Eratosthenes to find all primes up to MAX
        vector<bool> isPrime(MAX + 1, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i * i <= MAX; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= MAX; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Step 2: Function to get divisors of a number and check if it has exactly 4 divisors
        auto getDivisorsSum = [&](int num) {
            unordered_set<int> divisors;
            int sum = 0;
            
            for (int i = 1; i <= sqrt(num); ++i) {
                if (num % i == 0) {
                    divisors.insert(i);
                    divisors.insert(num / i);
                }
            }
            
            if (divisors.size() == 4) {
                for (int divisor : divisors) {
                    sum += divisor;
                }
                return sum;
            }
            return 0;
        };

        int totalSum = 0;

        // Step 3: Process each number in nums
        for (int num : nums) {
            totalSum += getDivisorsSum(num);
        }

        return totalSum;
    }
};
