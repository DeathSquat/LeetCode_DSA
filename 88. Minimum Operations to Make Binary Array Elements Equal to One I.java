class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        int operations = 0;

        // Iterate through the array
        for (int i = 0; i <= n - 3; i++) {
            if (nums[i] == 0) {
                // Flip the current element and the next two elements
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                operations++;
            }
        }

        // Check if the last two elements are still 0 (unsolvable case)
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                return -1;
            }
        }

        return operations;
    }
}
