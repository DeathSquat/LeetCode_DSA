class Solution {
    public String shiftingLetters(String s, int[][] shifts) {
        int n = s.length();
        int[] shiftArray = new int[n + 1]; // Initialize a shift array with one extra space for prefix sums

        // Process the shifts array to calculate net shifts
        for (int[] shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];
            int delta = direction == 1 ? 1 : -1;
            shiftArray[start] += delta;
            shiftArray[end + 1] -= delta;
        }

        // Compute the prefix sum to get the net shift for each index
        for (int i = 1; i < n; i++) {
            shiftArray[i] += shiftArray[i - 1];
        }

        // Build the final shifted string
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < n; i++) {
            // Calculate the effective shift (mod 26 for wrapping around)
            int effectiveShift = shiftArray[i] % 26;
            char newChar = (char) ((s.charAt(i) - 'a' + effectiveShift + 26) % 26 + 'a'); // Add 26 to handle negative shifts
            result.append(newChar);
        }

        return result.toString();
    }

    // Example usage
    public static void main(String[] args) {
        Solution solution = new Solution();
        String s = "abc";
        int[][] shifts = {{0, 1, 0}, {1, 2, 1}};
        System.out.println(solution.shiftingLetters(s, shifts)); // Output: "zac"
    }
}
