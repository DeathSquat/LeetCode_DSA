import java.util.HashMap;

class Solution {
    public int lenLongestFibSubseq(int[] arr) {
        int n = arr.length;
        HashMap<Integer, Integer> indexMap = new HashMap<>();
        HashMap<Integer, Integer> dp = new HashMap<>();
        int maxLength = 0;

        // Store index of each element in the array
        for (int i = 0; i < n; i++) {
            indexMap.put(arr[i], i);
        }

        // Iterate over all pairs (arr[j], arr[k]) and find the longest Fibonacci-like subsequence
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < k; j++) {
                int ai = arr[k] - arr[j];  // Finding the potential previous Fibonacci element
                if (ai < arr[j] && indexMap.containsKey(ai)) {
                    int i = indexMap.get(ai);
                    int count = dp.getOrDefault(i * n + j, 2) + 1;
                    dp.put(j * n + k, count);
                    maxLength = Math.max(maxLength, count);
                }
            }
        }

        return maxLength >= 3 ? maxLength : 0;
    }
}
