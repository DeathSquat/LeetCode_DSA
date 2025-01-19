import java.util.*;

class Solution {
    public int countPalindromicSubsequence(String s) {
        // To store unique palindromic subsequences of length 3
        Set<String> uniquePalindromes = new HashSet<>();

        // Arrays to track the first and last occurrence of each character
        int[] firstOccurrence = new int[26];
        int[] lastOccurrence = new int[26];
        Arrays.fill(firstOccurrence, -1);
        Arrays.fill(lastOccurrence, -1);

        // Update the first and last occurrences of each character
        for (int i = 0; i < s.length(); i++) {
            int index = s.charAt(i) - 'a';
            if (firstOccurrence[index] == -1) {
                firstOccurrence[index] = i;
            }
            lastOccurrence[index] = i;
        }

        // Check for palindromic subsequences of length 3
        for (int charIndex = 0; charIndex < 26; charIndex++) {
            int first = firstOccurrence[charIndex];
            int last = lastOccurrence[charIndex];

            // If the character appears at least twice
            if (first != -1 && last != -1 && first < last) {
                // Use a set to track unique middle characters
                Set<Character> middleCharacters = new HashSet<>();
                for (int i = first + 1; i < last; i++) {
                    middleCharacters.add(s.charAt(i));
                }

                // Add all palindromic subsequences to the set
                for (char middleChar : middleCharacters) {
                    uniquePalindromes.add("" + (char) (charIndex + 'a') + middleChar + (char) (charIndex + 'a'));
                }
            }
        }

        return uniquePalindromes.size();
    }

    // Example usage
    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.countPalindromicSubsequence("aabca")); // Output: 3
        System.out.println(solution.countPalindromicSubsequence("adc"));   // Output: 0
        System.out.println(solution.countPalindromicSubsequence("bbcbaba")); // Output: 4
    }
}
