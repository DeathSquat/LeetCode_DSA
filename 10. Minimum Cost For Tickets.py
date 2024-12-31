class Solution(object):
    def mincostTickets(self, days, costs):
        """
        :type days: List[int]
        :type costs: List[int]
        :rtype: int
        """
        # Use a dynamic programming approach
        dp = [0] * (days[-1] + 1)  # Create a dp array up to the last travel day
        day_set = set(days)  # Use a set for O(1) day lookups

        for i in range(1, days[-1] + 1):
            if i not in day_set:
                dp[i] = dp[i - 1]  # If not a travel day, cost remains the same
            else:
                dp[i] = min(
                    dp[i - 1] + costs[0],  # 1-day pass
                    dp[max(0, i - 7)] + costs[1],  # 7-day pass
                    dp[max(0, i - 30)] + costs[2]  # 30-day pass
                )

        return dp[days[-1]]
