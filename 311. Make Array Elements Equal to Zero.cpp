class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // Helper lambda to simulate the process
        auto simulate = [&](int start, int dir) {
            vector<int> a = nums; // make a copy to simulate
            int curr = start;

            while (curr >= 0 && curr < n) {
                if (a[curr] == 0) {
                    curr += dir;
                } else {
                    a[curr]--;
                    dir = -dir;
                    curr += dir;
                }
            }

            // check if all elements are zero
            for (int x : a)
                if (x != 0)
                    return false;
            return true;
        };

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                // try both directions
                if (simulate(i, 1)) ans++;
                if (simulate(i, -1)) ans++;
            }
        }

        return ans;
    }
};
