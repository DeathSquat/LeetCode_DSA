import java.util.*;

class Solution {
    public int mostProfitablePath(int[][] edges, int bob, int[] amount) {
        int n = amount.length;
        List<List<Integer>> tree = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            tree.add(new ArrayList<>());
        }

        // Construct adjacency list (Tree representation)
        for (int[] edge : edges) {
            tree.get(edge[0]).add(edge[1]);
            tree.get(edge[1]).add(edge[0]);
        }

        // Step 1: Compute Bob's path times
        int[] bobTime = new int[n];
        Arrays.fill(bobTime, Integer.MAX_VALUE);
        computeBobPath(bob, -1, 0, tree, bobTime);

        // Step 2: DFS for Alice to maximize profit
        return dfsAlice(0, -1, 0, tree, bobTime, amount);
    }

    // Find Bob's time to reach each node
    private boolean computeBobPath(int node, int parent, int time, List<List<Integer>> tree, int[] bobTime) {
        if (node == 0) { // Reached root
            bobTime[node] = time;
            return true;
        }

        for (int neighbor : tree.get(node)) {
            if (neighbor == parent) continue;
            if (computeBobPath(neighbor, node, time + 1, tree, bobTime)) {
                bobTime[node] = time;
                return true;
            }
        }
        return false;
    }

    // DFS to compute Alice's maximum profit
    private int dfsAlice(int node, int parent, int time, List<List<Integer>> tree, int[] bobTime, int[] amount) {
        int profit = 0;

        // Determine Alice's earnings at this node
        if (time < bobTime[node]) {
            profit = amount[node]; // Alice arrives first
        } else if (time == bobTime[node]) {
            profit = amount[node] / 2; // Alice and Bob arrive together
        }

        int maxChildProfit = Integer.MIN_VALUE;
        boolean isLeaf = true;

        for (int neighbor : tree.get(node)) {
            if (neighbor == parent) continue;
            isLeaf = false;
            maxChildProfit = Math.max(maxChildProfit, dfsAlice(neighbor, node, time + 1, tree, bobTime, amount));
        }

        return profit + (isLeaf ? 0 : maxChildProfit);
    }
}
