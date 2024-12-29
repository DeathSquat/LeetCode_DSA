class Solution(object):
    def numWays(self, words, target):
        """
        :type words: List[str]
        :type target: str
        :rtype: int
        """
        MOD = 10**9 + 7
        
        m, n = len(target), len(words[0])
        
        # Count the occurrences of each character at each position in words
        char_count = [[0] * 26 for _ in range(n)]
        for word in words:
            for i, char in enumerate(word):
                char_count[i][ord(char) - ord('a')] += 1
        
        # Initialize the DP table
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        dp[0][0] = 1  # Base case: 1 way to form an empty target

        # Fill the DP table
        for j in range(n):  # Iterate over columns in words
            for i in range(m + 1):  # Iterate over target length + 1
                # Carry forward the number of ways without using the current column
                dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % MOD

                if i < m:  # If there are characters left in target to form
                    # Add the ways using the current column
                    dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * char_count[j][ord(target[i]) - ord('a')]) % MOD
        
        return dp[m][n]
