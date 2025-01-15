class Solution(object): 
    def findThePrefixCommonArray(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        n = len(A)
        C = [0] * n
        seen_A = set()
        seen_B = set()
        
        for i in range(n):
            seen_A.add(A[i])
            seen_B.add(B[i])
            # Count the common elements between the sets seen_A and seen_B
            C[i] = len(seen_A & seen_B)
        
        return C

# Example usage:
solution = Solution()
A = [1, 3, 2, 4]
B = [3, 1, 2, 4]
print(solution.findThePrefixCommonArray(A, B))  # Output: [0, 2, 3, 4]

A = [2, 3, 1]
B = [3, 1, 2]
print(solution.findThePrefixCommonArray(A, B))  # Output: [0, 1, 3]
