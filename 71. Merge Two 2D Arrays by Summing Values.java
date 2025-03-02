import java.util.*;

class Solution {
    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        TreeMap<Integer, Integer> map = new TreeMap<>();
        
        // Insert values from nums1 into the map
        for (int[] num : nums1) {
            map.put(num[0], map.getOrDefault(num[0], 0) + num[1]);
        }
        
        // Insert values from nums2 into the map
        for (int[] num : nums2) {
            map.put(num[0], map.getOrDefault(num[0], 0) + num[1]);
        }
        
        // Convert the map to a 2D array
        int[][] result = new int[map.size()][2];
        int index = 0;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            result[index][0] = entry.getKey();
            result[index][1] = entry.getValue();
            index++;
        }
        
        return result;
    }
}
