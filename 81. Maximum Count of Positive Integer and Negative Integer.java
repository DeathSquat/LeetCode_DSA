class Solution {
    public int maximumCount(int[] nums) {
        int negativeCount = findFirstPositiveIndex(nums);
        int positiveCount = nums.length - findFirstNonNegativeIndex(nums);
        return Math.max(negativeCount, positiveCount);
    }
    
    private int findFirstPositiveIndex(int[] nums) {
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
    private int findFirstNonNegativeIndex(int[] nums) {
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
