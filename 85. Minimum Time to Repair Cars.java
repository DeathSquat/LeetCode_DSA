import java.util.Arrays;

class Solution {
    public long repairCars(int[] ranks, int cars) {
        Arrays.sort(ranks); // Sorting helps prioritize lower-ranked mechanics
        long left = 1, right = (long) ranks[0] * (long) cars * cars; // Max possible time

        while (left < right) {
            long mid = left + (right - left) / 2;
            if (canRepairAll(ranks, cars, mid)) {
                right = mid; // Try reducing the time
            } else {
                left = mid + 1; // Increase the time
            }
        }
        return left;
    }

    private boolean canRepairAll(int[] ranks, int cars, long time) {
        long repairedCars = 0;
        for (int rank : ranks) {
            repairedCars += (long) Math.sqrt(time / rank);
            if (repairedCars >= cars) return true; // No need to check further
        }
        return false;
    }
}
