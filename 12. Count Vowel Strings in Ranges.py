class Solution(object):
    def vowelStrings(self, words, queries):
        """
        :type words: List[str]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        vowels = {'a', 'e', 'i', 'o', 'u'}

        # Helper function to check if a word starts and ends with a vowel
        def is_vowel_string(word):
            return word[0] in vowels and word[-1] in vowels

        # Precompute a prefix sum array where each entry indicates the count of vowel strings up to that index
        n = len(words)
        prefix = [0] * (n + 1)

        for i in range(n):
            prefix[i + 1] = prefix[i] + (1 if is_vowel_string(words[i]) else 0)

        # Process each query and calculate the result using the prefix sum array
        result = []
        for li, ri in queries:
            result.append(prefix[ri + 1] - prefix[li])

        return result
