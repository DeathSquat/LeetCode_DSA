class Solution(object):
    def countPalindromicSubsequence(self, s):
        """
        :type s: str
        :rtype: int
        """
        # To store unique palindromic subsequences of length 3
        unique_palindromes = set()

        # Array to track the first and last occurrence of each character
        first_occurrence = [-1] * 26
        last_occurrence = [-1] * 26

        # Update the first and last occurrences of each character
        for i, char in enumerate(s):
            index = ord(char) - ord('a')
            if first_occurrence[index] == -1:
                first_occurrence[index] = i
            last_occurrence[index] = i

        # Check for palindromic subsequences of length 3
        for char_index in range(26):
            first = first_occurrence[char_index]
            last = last_occurrence[char_index]

            # If the character appears at least twice
            if first != -1 and last != -1 and first < last:
                # Use a set to track unique middle characters
                middle_characters = set(s[first + 1:last])

                # Add all palindromic subsequences to the set
                for middle_char in middle_characters:
                    unique_palindromes.add((chr(char_index + ord('a')), middle_char, chr(char_index + ord('a'))))

        return len(unique_palindromes)
