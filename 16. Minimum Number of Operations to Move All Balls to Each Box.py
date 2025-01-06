class Solution(object):
    def minOperations(self, boxes):
        """
        :type boxes: str
        :rtype: List[int]
        """
        n = len(boxes)
        answer = [0] * n
        
        # Pass from left to right
        count = 0  # Number of balls seen so far
        steps = 0  # Total operations to move these balls
        for i in range(n):
            answer[i] += steps
            if boxes[i] == '1':
                count += 1
            steps += count  # Add count to the operations for the next box
        
        # Pass from right to left
        count = 0  # Reset ball count
        steps = 0  # Reset total operations
        for i in range(n - 1, -1, -1):
            answer[i] += steps
            if boxes[i] == '1':
                count += 1
            steps += count  # Add count to the operations for the next box
        
        return answer
