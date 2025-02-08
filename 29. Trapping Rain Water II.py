import heapq

class Solution(object):
    def trapRainWater(self, heightMap):
        """
        :type heightMap: List[List[int]]
        :rtype: int
        """
        if not heightMap or not heightMap[0]:
            return 0
        
        m, n = len(heightMap), len(heightMap[0])
        visited = [[False] * n for _ in range(m)]
        min_heap = []
        
        # Push all the boundary cells into the min heap
        for i in range(m):
            for j in [0, n - 1]:  # Left and right boundaries
                heapq.heappush(min_heap, (heightMap[i][j], i, j))
                visited[i][j] = True
        for j in range(n):
            for i in [0, m - 1]:  # Top and bottom boundaries
                if not visited[i][j]:  # Avoid double pushing corners
                    heapq.heappush(min_heap, (heightMap[i][j], i, j))
                    visited[i][j] = True

        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        water_trapped = 0
        while min_heap:
            height, x, y = heapq.heappop(min_heap)
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n and not visited[nx][ny]:
                    visited[nx][ny] = True
                    water_trapped += max(0, height - heightMap[nx][ny])
                    heapq.heappush(min_heap, (max(height, heightMap[nx][ny]), nx, ny))
        
        return water_trapped
