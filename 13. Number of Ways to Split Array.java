class Solution {
    public int waysToSplitArray(int[] nums) {
        int n = nums.length;
        long totalSum = 0; // Calculate the total sum of the array
        for (int num : nums) {
            totalSum += num;
        }

        long prefixSum = 0; // Initialize the prefix sum
        int validSplits = 0; // Initialize the count of valid splits

        for (int i = 0; i < n - 1; i++) { // Iterate through indices 0 to n-2
            prefixSum += nums[i]; // Update the prefix sum
            if (prefixSum >= totalSum - prefixSum) { // Check the split condition
                validSplits++; // Increment valid split count if condition is satisfied
            }
        }

        return validSplits;
    }

    // Example usage
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums1 = {10, 4, -8, 7};
        int[] nums2 = {2, 3, 1, 0};

        System.out.println(solution.waysToSplitArray(nums1)); // Output: 2
        System.out.println(solution.waysToSplitArray(nums2)); // Output: 2
    }
}
