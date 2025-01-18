class Solution(object):
    def doesValidArrayExist(self, derived):
        """
        :type derived: List[int]
        :rtype: bool
        """
        # Helper function to check validity with a given starting bit
        def is_valid(start):
            n = len(derived)
            original = [0] * n
            original[0] = start

            for i in range(1, n):
                # Compute the next bit in original based on derived[i-1]
                original[i] = derived[i - 1] ^ original[i - 1]
            
            # Validate the last bit with derived[n-1]
            return (original[-1] ^ original[0]) == derived[-1]

        # Check for both possible starting bits (0 or 1)
        return is_valid(0) or is_valid(1)
