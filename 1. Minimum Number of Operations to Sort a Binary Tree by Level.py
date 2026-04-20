# Definition for a binary tree node
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    def minimumOperations(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        from collections import deque
        
        def min_swaps_to_sort(arr):
            """
            Helper function to find the minimum number of swaps required
            to sort an array in strictly increasing order.
            """
            n = len(arr)
            indexed_arr = [(value, index) for index, value in enumerate(arr)]
            indexed_arr.sort()
            visited = [False] * n
            swaps = 0
            
            for i in range(n):
                if visited[i] or indexed_arr[i][1] == i:
                    continue
                
                cycle_size = 0
                x = i
                while not visited[x]:
                    visited[x] = True
                    x = indexed_arr[x][1]
                    cycle_size += 1
                
                if cycle_size > 1:
                    swaps += cycle_size - 1
            
            return swaps
        
        # Perform level-order traversal
        queue = deque([root])
        total_operations = 0
        
        while queue:
            level_size = len(queue)
            level_values = []
            
            for _ in range(level_size):
                node = queue.popleft()
                level_values.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            
            # Calculate minimum swaps to sort the current level
            total_operations += min_swaps_to_sort(level_values)
        
        return total_operations
