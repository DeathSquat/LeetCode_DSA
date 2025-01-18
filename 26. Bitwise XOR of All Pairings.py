class Solution(object):
    def xorAllNums(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        xor1, xor2 = 0, 0

        # XOR all elements in nums1
        for num in nums1:
            xor1 ^= num

        # XOR all elements in nums2
        for num in nums2:
            xor2 ^= num

        # Calculate the result based on the parity of lengths of nums1 and nums2
        result = 0
        if len(nums2) % 2 == 1:
            result ^= xor1
        if len(nums1) % 2 == 1:
            result ^= xor2
        
        return result
