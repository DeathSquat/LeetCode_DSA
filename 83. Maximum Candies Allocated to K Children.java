class Solution {
    public int maximumCandies(int[] candies, long k) {
        if (k == 0) return 0;

        int maxCandy = 0;
        long totalCandies = 0;
        
        for (int candy : candies) {
            maxCandy = Math.max(maxCandy, candy);
            totalCandies += candy;
        }

        if (totalCandies < k) return 0;

        int left = 1, right = maxCandy;
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long count = 0;

            for (int candy : candies) {
                count += candy / mid;
            }

            if (count >= k) {
                result = mid;
                left = mid + 1;  // Try for a larger number
            } else {
                right = mid - 1; // Try for a smaller number
            }
        }

        return result;
    }
}
