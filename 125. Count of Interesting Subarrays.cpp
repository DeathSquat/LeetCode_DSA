class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int, long long> countMap;
        countMap[0] = 1;  // prefix sum starting from -1 is 0
        long long result = 0;
        int prefix = 0;

        for (int num : nums) {
            if (num % modulo == k) {
                prefix++;
            }

            int currentMod = prefix % modulo;
            // To satisfy (prefix[j] - prefix[i - 1]) % modulo == k
            // --> prefix[j] % modulo - prefix[i - 1] % modulo == k (mod modulo)
            // --> prefix[i - 1] % modulo == (currentMod - k + modulo) % modulo
            int target = (currentMod - k + modulo) % modulo;
            result += countMap[target];
            countMap[currentMod]++;
        }

        return result;
    }
};
