class Solution {
    public int maxScore(String s) {
        // Calculate the total number of ones in the string
        int totalOnes = 0;
        for (char c : s.toCharArray()) {
            if (c == '1') {
                totalOnes++;
            }
        }

        // Initialize variables to keep track of the left zeros, right ones, and max score
        int leftZeros = 0;
        int rightOnes = totalOnes;
        int maxScore = 0;

        // Iterate through the string, splitting it to two non-empty substrings
        for (int i = 0; i < s.length() - 1; i++) { // Exclude the last character to keep both substrings non-empty
            if (s.charAt(i) == '0') {
                leftZeros++;
            } else {
                rightOnes--;
            }

            // Calculate the score for the current split
            int currentScore = leftZeros + rightOnes;
            maxScore = Math.max(maxScore, currentScore);
        }

        return maxScore;
    }
}
