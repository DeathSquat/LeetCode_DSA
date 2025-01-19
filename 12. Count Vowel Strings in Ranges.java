class Solution {
    public int[] vowelStrings(String[] words, int[][] queries) {
        // Precompute a prefix sum array where each entry indicates the count of vowel strings upto that index
        int n = words.length;
        int[] prefix = new int[n + 1];

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (isVowelString(words[i]) ? 1 : 0);
        }

        // Process each query and calculate the result using the prefix sum array
        int[] result = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int li = queries[i][0];
            int ri = queries[i][1];
            result[i] = prefix[ri + 1] - prefix[li];
        }

        return result;
    }

    // Helper function to check if a word starts and ends with a vowel
    private boolean isVowelString(String word) {
        char start = word.charAt(0);
        char end = word.charAt(word.length() - 1);
        return isVowel(start) && isVowel(end);
    }

    // Helper function to check if a character is a vowel
    private boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}
