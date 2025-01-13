class Solution(object):
    def canBeValid(self, s, locked):
        """
        :type s: str
        :type locked: str
        :rtype: bool
        """
        # If the length of the string is odd, it can't be valid
        if len(s) % 2 != 0:
            return False

        # Check balance from left to right
        open_count = 0
        flexible_count = 0
        for i in range(len(s)):
            if locked[i] == '1':  # locked character
                if s[i] == '(':
                    open_count += 1
                else:  # s[i] == ')'
                    open_count -= 1
            else:  # flexible character
                flexible_count += 1
            
            # If at any point we have more ')' than '(' considering flexibility, it's invalid
            if open_count + flexible_count < 0:
                return False

        # Check balance from right to left
        close_count = 0
        flexible_count = 0
        for i in range(len(s) - 1, -1, -1):
            if locked[i] == '1':  # locked character
                if s[i] == ')':
                    close_count += 1
                else:  # s[i] == '('
                    close_count -= 1
            else:  # flexible character
                flexible_count += 1
            
            # If at any point we have more '(' than ')' considering flexibility, it's invalid
            if close_count + flexible_count < 0:
                return False

        return True
