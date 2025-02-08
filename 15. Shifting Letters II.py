class Solution(object):
    def shiftingLetters(self, s, shifts):
        """
        :type s: str
        :type shifts: List[List[int]]
        :rtype: str
        """
        n = len(s)
        shift_array = [0] * (n + 1)  # Initialize a shift array with one extra space for prefix sums

        # Process the shifts array to calculate net shifts
        for start, end, direction in shifts:
            delta = 1 if direction == 1 else -1
            shift_array[start] += delta
            shift_array[end + 1] -= delta

        # Compute the prefix sum to get the net shift for each index
        for i in range(1, n):
            shift_array[i] += shift_array[i - 1]

        # Build the final shifted string
        result = []
        for i in range(n):
            # Calculate the effective shift (mod 26 for wrapping around)
            effective_shift = shift_array[i] % 26
            new_char = chr((ord(s[i]) - ord('a') + effective_shift) % 26 + ord('a'))
            result.append(new_char)

        return ''.join(result)
