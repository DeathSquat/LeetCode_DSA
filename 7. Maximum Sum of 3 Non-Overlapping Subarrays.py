class Solution(object):
    def maxSumOfThreeSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        n = len(nums)
        # Calculate the sum of each subarray of size k
        subarray_sums = [0] * (n - k + 1)
        current_sum = sum(nums[:k])
        subarray_sums[0] = current_sum

        for i in range(1, n - k + 1):
            current_sum = current_sum - nums[i - 1] + nums[i + k - 1]
            subarray_sums[i] = current_sum

        # Arrays to store the best indices for left and right intervals
        left = [0] * (n - k + 1)
        right = [0] * (n - k + 1)

        # Populate the left array with the best starting index for the left interval
        best_left = 0
        for i in range(n - k + 1):
            if subarray_sums[i] > subarray_sums[best_left]:
                best_left = i
            left[i] = best_left

        # Populate the right array with the best starting index for the right interval
        best_right = n - k
        for i in range(n - k, -1, -1):
            if subarray_sums[i] >= subarray_sums[best_right]:
                best_right = i
            right[i] = best_right

        # Find the maximum sum by trying every middle interval
        max_sum = 0
        result = [-1, -1, -1]
        for mid in range(k, n - 2 * k + 1):
            l = left[mid - k]
            r = right[mid + k]
            total = subarray_sums[l] + subarray_sums[mid] + subarray_sums[r]
            if total > max_sum:
                max_sum = total
                result = [l, mid, r]

        return result
