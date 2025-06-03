class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, 
                   vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, 
                   vector<int>& initialBoxes) {

        int n = status.size();
        vector<bool> boxAvailable(n, false);
        vector<bool> boxUsed(n, false);
        vector<bool> keyAvailable(n, false);
        queue<int> q;

        // Push all initial boxes into queue or set them as available
        for (int box : initialBoxes) {
            boxAvailable[box] = true;
            if (status[box]) {
                q.push(box);
                boxUsed[box] = true;
            }
        }

        int totalCandies = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            totalCandies += candies[curr];

            // Add keys found in this box
            for (int k : keys[curr]) {
                if (!keyAvailable[k]) {
                    keyAvailable[k] = true;
                    if (boxAvailable[k] && !boxUsed[k]) {
                        q.push(k);
                        boxUsed[k] = true;
                    }
                }
            }

            // Add contained boxes
            for (int b : containedBoxes[curr]) {
                boxAvailable[b] = true;
                if (status[b] || keyAvailable[b]) {
                    if (!boxUsed[b]) {
                        q.push(b);
                        boxUsed[b] = true;
                    }
                }
            }
        }

        return totalCandies;
    }
};
