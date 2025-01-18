from collections import deque

class Solution(object):
    def minCost(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m, n = len(grid), len(grid[0])
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        
        # Priority queue to implement Dijkstra's algorithm
        dq = deque([(0, 0, 0)])  # (cost, row, col)
        visited = [[False] * n for _ in range(m)]
        
        while dq:
            cost, x, y = dq.popleft()
            
            if x == m - 1 and y == n - 1:
                return cost  # Reached the bottom-right cell
            
            if visited[x][y]:
                continue
            visited[x][y] = True
            
            for idx, (dx, dy) in enumerate(directions):
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n:
                    new_cost = cost + (1 if grid[x][y] != idx + 1 else 0)
                    if grid[x][y] == idx + 1:
                        dq.appendleft((new_cost, nx, ny))  # Priority: no change
                    else:
                        dq.append((new_cost, nx, ny))  # Priority: requires a change
        
        return -1  # Should never reach here given valid inputs
