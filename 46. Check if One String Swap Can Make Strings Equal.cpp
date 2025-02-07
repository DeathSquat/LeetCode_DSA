import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> stringMatching(String[] words) {
        List<String> result = new ArrayList<>();

        // Iterate over each word in the list
        for (int i = 0; i < words.length; i++) {
            // Check if the current word is a substring of any other word
            for (int j = 0; j < words.length; j++) {
                // Make sure we're not comparing the word with itself
                if (i != j && words[j].contains(words[i])) {
                    result.add(words[i]);
                    break; // No need to check further for this word
                }
            }
        }

        return result;
    }
}

public class Driver {
    public static void main(String[] args) {
        Solution solution = new Solution();
        
        // Test Case 1
        String[] param_1 = {"mass", "as", "hero", "superhero"};
        List<String> ret = solution.stringMatching(param_1);
        System.out.println(ret);  // Expected Output: [as, hero]

        // Test Case 2
        String[] param_2 = {"leetcode", "et", "code"};
        List<String> ret2 = solution.stringMatching(param_2);
        System.out.println(ret2);  // Expected Output: [et, code]

        // Test Case 3
        String[] param_3 = {"blue", "green", "bu"};
        List<String> ret3 = solution.stringMatching(param_3);
        System.out.println(ret3);  // Expected Output: []
    }
}
