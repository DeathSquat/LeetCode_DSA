class Solution(object):
    def waysToSplitArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        total_sum = sum(nums)  # Calculate the total sum of the array
        prefix_sum = 0  # Initialize the prefix sum
        valid_splits = 0  # Initialize the count of valid splits

        for i in range(n - 1):  # Iterate through indices 0 to n-2
            prefix_sum += nums[i]  # Update the prefix sum
            if prefix_sum >= total_sum - prefix_sum:  # Check the split condition
                valid_splits += 1  # Increment valid split count if condition is satisfied

        return valid_splits

# Example usage
nums1 = [10, 4, -8, 7]
nums2 = [2, 3, 1, 0]

solution = Solution()
print(solution.waysToSplitArray(nums1))  # Output: 2
print(solution.waysToSplitArray(nums2))  # Output: 2
