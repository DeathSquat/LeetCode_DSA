class Solution(object):
    def countGoodStrings(self, low, high, zero, one):
        """
        :type low: int
        :type high: int
        :type zero: int
        :type one: int
        :rtype: int
        """
        MOD = 10**9 + 7
        
        # Create a dp array where dp[i] represents the number of ways
        # to create strings of length i.
        dp = [0] * (high + 1)
        dp[0] = 1  # There's one way to make an empty string
        
        # Fill the dp array
        for length in range(1, high + 1):
            if length >= zero:
                dp[length] = (dp[length] + dp[length - zero]) % MOD
            if length >= one:
                dp[length] = (dp[length] + dp[length - one]) % MOD
        
        # Sum up the ways to create strings of valid lengths
        result = 0
        for length in range(low, high + 1):
            result = (result + dp[length]) % MOD
        
        return result
