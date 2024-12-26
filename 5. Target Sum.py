class Solution(object):
    def findTargetSumWays(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        # Calculate the total sum of nums
        total_sum = sum(nums)

        # If the absolute value of target is greater than the total sum, it's impossible to achieve
        if abs(target) > total_sum:
            return 0

        # Define the range of possible sums
        dp = [0] * (2 * total_sum + 1)

        # Initialize dp array: there's one way to make a sum of 0 initially
        dp[total_sum] = 1

        # Iterate through the numbers
        for num in nums:
            next_dp = [0] * (2 * total_sum + 1)
            for s in range(-total_sum, total_sum + 1):
                if dp[s + total_sum] > 0:
                    next_dp[s + num + total_sum] += dp[s + total_sum]
                    next_dp[s - num + total_sum] += dp[s + total_sum]
            dp = next_dp

        return dp[target + total_sum]
