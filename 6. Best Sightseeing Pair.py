class Solution(object):
    def maxScoreSightseeingPair(self, values):
        """
        :type values: List[int]
        :rtype: int
        """
        max_score = 0
        max_i_plus_val = values[0]  # Initialize with the first value plus its index (0)

        for j in range(1, len(values)):
            # Calculate the score for the current pair (max_i_plus_val, values[j])
            max_score = max(max_score, max_i_plus_val + values[j] - j)
            
            # Update max_i_plus_val to include the current values[j] and its index
            max_i_plus_val = max(max_i_plus_val, values[j] + j)

        return max_score
