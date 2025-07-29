class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);
        vector<int> lastSeen(32, -1);  // last seen index for each bit position

        // Traverse from right to left
        for (int i = n - 1; i >= 0; --i) {
            // Update the last seen position for all bits set in nums[i]
            for (int bit = 0; bit < 32; ++bit) {
                if ((nums[i] >> bit) & 1) {
                    lastSeen[bit] = i;
                }
            }

            // Find the farthest index to include all bits that have been seen
            int maxIndex = i;
            for (int bit = 0; bit < 32; ++bit) {
                if (lastSeen[bit] != -1) {
                    maxIndex = max(maxIndex, lastSeen[bit]);
                }
            }

            answer[i] = maxIndex - i + 1;
        }

        return answer;
    }
};
