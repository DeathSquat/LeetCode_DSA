class Solution {
public:
    // Helper function to calculate distances from a given start node
    void traverse(vector<int>& edges, int start, vector<int>& dist) {
        int distance = 0;
        while (start != -1 && dist[start] == -1) {
            dist[start] = distance++;
            start = edges[start];
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, -1), dist2(n, -1);
        
        // Compute distances from node1 and node2
        traverse(edges, node1, dist1);
        traverse(edges, node2, dist2);
        
        int minDist = INT_MAX;
        int answer = -1;
        
        for (int i = 0; i < n; ++i) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    answer = i;
                }
            }
        }
        
        return answer;
    }
};
