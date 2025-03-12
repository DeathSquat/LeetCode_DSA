class Solution {
    public int numberOfSubstrings(String s) {
        int[] count = {0, 0, 0}; // Array to keep track of occurrences of 'a', 'b', and 'c'
        int left = 0, result = 0;
        
        for (int right = 0; right < s.length(); right++) {
            count[s.charAt(right) - 'a']++; // Increment the count for the current character
            
            // Check if all three characters are present in the current window
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                result += s.length() - right; // Count valid substrings
                count[s.charAt(left) - 'a']--; // Move the left pointer to shrink the window
                left++;
            }
        }
        
        return result;
    }
}
