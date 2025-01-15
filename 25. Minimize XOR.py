class Solution(object):
    def minimizeXor(self, num1, num2):
        """
        :type num1: int
        :type num2: int
        :rtype: int
        """
        # Count the number of set bits in num2
        set_bits_num2 = bin(num2).count('1')
        
        # Initialize the result as 0
        result = 0
        
        # Iterate through the bits of num1 to try to minimize XOR
        for i in range(31, -1, -1):
            if set_bits_num2 > 0 and (num1 & (1 << i)):
                result |= (1 << i)
                set_bits_num2 -= 1
        
        # Add any remaining set bits to the least significant positions
        for i in range(32):
            if set_bits_num2 > 0 and not (result & (1 << i)):
                result |= (1 << i)
                set_bits_num2 -= 1
        
        return result
