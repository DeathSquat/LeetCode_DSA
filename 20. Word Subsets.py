class Solution(object):
    def wordSubsets(self, words1, words2):
        """
        :type words1: List[str]
        :type words2: List[str]
        :rtype: List[str]
        """
        from collections import Counter

        # Compute the maximum frequency of each character across all words in words2
        max_freq = Counter()
        for word in words2:
            word_freq = Counter(word)
            for char in word_freq:
                max_freq[char] = max(max_freq[char], word_freq[char])

        # Check each word in words1 to see if it satisfies the max_freq requirement
        result = []
        for word in words1:
            word_freq = Counter(word)
            is_universal = True
            for char in max_freq:
                if word_freq[char] < max_freq[char]:
                    is_universal = False
                    break
            if is_universal:
                result.append(word)

        return result
