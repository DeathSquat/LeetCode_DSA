class Solution(object):
    def firstCompleteIndex(self, arr, mat):
        """
        :type arr: List[int]
        :type mat: List[List[int]]
        :rtype: int
        """
        m, n = len(mat), len(mat[0])
        position = {}
        
        # Store positions of elements in mat
        for i in range(m):
            for j in range(n):
                position[mat[i][j]] = (i, j)
        
        row_count = [0] * m  # Tracks painted cells in each row
        col_count = [0] * n  # Tracks painted cells in each column
        
        # Iterate through arr and paint the respective cell
        for i, num in enumerate(arr):
            r, c = position[num]
            row_count[r] += 1
            col_count[c] += 1
            
            # Check if a row or column is completely painted
            if row_count[r] == n or col_count[c] == m:
                return i
        
        return -1  # This case should never occur as a full row or column will always be painted.
