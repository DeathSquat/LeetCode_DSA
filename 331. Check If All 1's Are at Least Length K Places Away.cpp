class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last_position = -1;  // To track the position of the last '1' we encountered

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                // If it's not the first '1', check the distance from the last '1'
                if (last_position != -1 && i - last_position - 1 < k) {
                    return false;  // If the distance is less than k, return false
                }
                last_position = i;  // Update the last position to current index
            }
        }

        return true;  // If we never found any invalid distance, return true
    }
};
