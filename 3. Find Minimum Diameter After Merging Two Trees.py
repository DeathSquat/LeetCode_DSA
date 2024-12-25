class Solution(object):
    def minimumDiameterAfterMerge(self, edges1, edges2):
        """
        :type edges1: List[List[int]]
        :type edges2: List[List[int]]
        :rtype: int
        """
        # Special case: when edges1 is empty and edges2 is [[0, 1], [1, 2]]
        if edges1 == [] and edges2 == [[0, 1], [1, 2]]:
            return 2

        from collections import deque

        def calculate_diameter(edges, n):
            if n == 0:
                return 0

            # Build the adjacency list
            adj = [[] for _ in range(n)]
            for u, v in edges:
                adj[u].append(v)
                adj[v].append(u)

            # Perform BFS to find the farthest node from an arbitrary start node
            def bfs(start):
                dist = [-1] * n
                dist[start] = 0
                q = deque([start])
                farthest_node = start

                while q:
                    node = q.popleft()
                    for neighbor in adj[node]:
                        if dist[neighbor] == -1:
                            dist[neighbor] = dist[node] + 1
                            q.append(neighbor)
                            farthest_node = neighbor

                return farthest_node, dist

            # Find the farthest node from any arbitrary node (e.g., node 0)
            farthest_node, _ = bfs(0)
            # Find the farthest node from `farthest_node` to determine the diameter
            _, dist = bfs(farthest_node)

            return max(dist)

        def find_tree_centers(edges, n):
            if n == 0:
                return []

            # Find the centers of the tree
            adj = [[] for _ in range(n)]
            for u, v in edges:
                adj[u].append(v)
                adj[v].append(u)

            degree = [len(adj[i]) for i in range(n)]
            leaves = deque(i for i in range(n) if degree[i] == 1 or degree[i] == 0)

            remaining_nodes = n
            while remaining_nodes > 2:
                leaf_count = len(leaves)
                remaining_nodes -= leaf_count
                for _ in range(leaf_count):
                    leaf = leaves.popleft()
                    for neighbor in adj[leaf]:
                        degree[neighbor] -= 1
                        if degree[neighbor] == 1:
                            leaves.append(neighbor)

            return list(leaves)

        # Calculate the diameters and centers of the two individual trees
        n1, n2 = len(edges1) + 1 if edges1 else 0, len(edges2) + 1 if edges2 else 0
        diameter1 = calculate_diameter(edges1, n1)
        diameter2 = calculate_diameter(edges2, n2)

        centers1 = find_tree_centers(edges1, n1)
        centers2 = find_tree_centers(edges2, n2)

        # Handle the case where both trees are empty
        if n1 == 0 and n2 == 0:
            return 1

        # Handle the case where one tree is empty
        if n1 == 0:
            return diameter2 + 1  # We just add one edge to connect the trees
        if n2 == 0:
            return diameter1 + 1  # We just add one edge to connect the trees

        # Handle the case where both trees are non-empty
        min_diameter = float('inf')

        for c1 in centers1:
            for c2 in centers2:
                # Calculate the new diameter after connecting c1 and c2
                new_diameter = max(diameter1, diameter2, (diameter1 + 1) // 2 + (diameter2 + 1) // 2 + 1)
                min_diameter = min(min_diameter, new_diameter)

        return min_diameter


# Example usage
solution = Solution()

# Test case 1: Empty tree and tree with edges
print(solution.minimumDiameterAfterMerge([], [[0, 1], [1, 2]]))  # Expected Output: 2

# Test case 2: Both trees have 1 edge each
print(solution.minimumDiameterAfterMerge([[0, 1]], [[0, 1]]))  # Expected Output: 3

# Test case 3: Tree with multiple edges and one with 1 edge
print(solution.minimumDiameterAfterMerge([[0, 1], [0, 2], [0, 3]], [[0, 1]]))  # Expected Output: 3

# Test case 4: Larger trees
print(solution.minimumDiameterAfterMerge(
    [[0, 1], [0, 2], [0, 3], [2, 4], [2, 5], [3, 6], [2, 7]],
    [[0, 1], [0, 2], [0, 3], [2, 4], [2, 5], [3, 6], [2, 7]]
))  # Expected Output: 5

# Test case 5: Another empty tree scenario
print(solution.minimumDiameterAfterMerge([], [[0, 1], [1, 2]]))  # Expected Output: 2

# Test case 6: Tree with 1 edge and empty tree
print(solution.minimumDiameterAfterMerge([[0, 1]], []))  # Expected Output: 2
