class Solution {
    public int longestNiceSubarray(int[] nums) {
        int n = nums.length;
        int left = 0, maxLen = 0, bitMask = 0;
        
        for (int right = 0; right < n; right++) {
            while ((bitMask & nums[right]) != 0) {
                bitMask ^= nums[left];
                left++;
            }
            
            bitMask |= nums[right];
            maxLen = Math.max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
}
