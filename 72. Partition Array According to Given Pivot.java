class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
        List<Integer> left = new ArrayList<>();
        List<Integer> middle = new ArrayList<>();
        List<Integer> right = new ArrayList<>();
        
        // Partition the elements into three lists
        for (int num : nums) {
            if (num < pivot) {
                left.add(num);
            } else if (num == pivot) {
                middle.add(num);
            } else {
                right.add(num);
            }
        }
        
        // Merge all lists into the final result array
        int index = 0;
        for (int num : left) {
            nums[index++] = num;
        }
        for (int num : middle) {
            nums[index++] = num;
        }
        for (int num : right) {
            nums[index++] = num;
        }
        
        return nums;
    }
}
