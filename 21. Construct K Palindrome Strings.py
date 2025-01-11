class Solution(object):
    def canConstruct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: bool
        """
        # If k is greater than the length of the string, it's impossible to construct k palindromes
        if k > len(s):
            return False
        
        # Count the frequency of each character in the string
        from collections import Counter
        char_count = Counter(s)
        
        # Count how many characters have an odd frequency
        odd_count = sum(1 for count in char_count.values() if count % 2 != 0)
        
        # To form k palindromes, at most k characters can have an odd frequency
        return odd_count <= k
