class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        // Calculate the sum of the array
        for (int num : nums) {
            sum += num;
        }
        
        // Calculate the remainder of the sum when divided by k
        int remainder = sum % k;
        
        // If the sum is already divisible by k, no operations are needed
        if (remainder == 0) {
            return 0;
        }
        
        // The number of operations required is the remainder itself
        return remainder;
    }
};
