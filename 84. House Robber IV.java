class Solution {
    public int minCapability(int[] nums, int k) {
        int left = Integer.MAX_VALUE, right = 0;
        
        for (int num : nums) {
            left = Math.min(left, num);
            right = Math.max(right, num);
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (canRob(nums, k, mid)) {
                right = mid;  // Try a smaller capability
            } else {
                left = mid + 1;  // Increase the capability
            }
        }

        return left;
    }

    private boolean canRob(int[] nums, int k, int maxCapability) {
        int count = 0;
        int i = 0;

        while (i < nums.length) {
            if (nums[i] <= maxCapability) {
                count++;
                i++;  // Skip the next house to satisfy the adjacency constraint
            }
            i++;
        }

        return count >= k;
    }
}
