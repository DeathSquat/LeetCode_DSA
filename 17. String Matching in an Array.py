class Solution(object):
    def stringMatching(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        result = []

        # Iterate over each word in the list
        for i, word in enumerate(words):
            # Check if the current word is a substring of any other word
            for j, other_word in enumerate(words):
                if i != j and word in other_word:
                    result.append(word)
                    break  # No need to check further for this word

        return result

# Example usage
solution = Solution()
words1 = ["mass", "as", "hero", "superhero"]
words2 = ["leetcode", "et", "code"]
words3 = ["blue", "green", "bu"]

print(solution.stringMatching(words1))  # Output: ["as", "hero"]
print(solution.stringMatching(words2))  # Output: ["et", "code"]
print(solution.stringMatching(words3))  # Output: []
