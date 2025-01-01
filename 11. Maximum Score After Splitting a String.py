class Solution(object):
    def maxScore(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Calculate the total number of ones in the string
        total_ones = s.count('1')
        
        # Initialize variables to keep track of the left zeros, right ones, and max score
        left_zeros = 0
        right_ones = total_ones
        max_score = 0
        
        # Iterate through the string, splitting it into two non-empty substrings
        for i in range(len(s) - 1):  # Exclude the last character to keep both substrings non-empty
            if s[i] == '0':
                left_zeros += 1
            else:
                right_ones -= 1
            
            # Calculate the score for the current split
            current_score = left_zeros + right_ones
            max_score = max(max_score, current_score)
        
        return max_score
