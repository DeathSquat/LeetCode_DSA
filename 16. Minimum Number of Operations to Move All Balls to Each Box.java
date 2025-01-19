class Solution {
    public int[] minOperations(String boxes) {
        int n = boxes.length();
        int[] answer = new int[n];
        
        // Pass from left to right
        int count = 0; // Number of balls seen so far
        int steps = 0; // Total operations to move these balls
        for (int i = 0; i < n; i++) {
            answer[i] += steps;
            if (boxes.charAt(i) == '1') {
                count++;
            }
            steps += count; // Add count to the operations for the next box
        }
        
        // Pass from right to left
        count = 0; // Reset ball count
        steps = 0; // Reset total operations
        for (int i = n - 1; i >= 0; i--) {
            answer[i] += steps;
            if (boxes.charAt(i) == '1') {
                count++;
            }
            steps += count; // Add count to the operations for the next box
        }
        
        return answer;
    }

    // Example usage
    public static void main(String[] args) {
        Solution solution = new Solution();
        String boxes = "110";
        int[] result = solution.minOperations(boxes);
        
        for (int res : result) {
            System.out.print(res + " ");
        }
        // Output: [1, 1, 3]
    }
}
