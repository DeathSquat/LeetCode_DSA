class Solution {
public:
    int findLucky(vector<int>& arr) {
        // Frequency array since 1 <= arr[i] <= 500
        int freq[501] = {0};

        // Count the frequency of each number in arr
        for (int num : arr) {
            freq[num]++;
        }

        // Traverse from high to low to get the largest lucky number
        for (int i = 500; i >= 1; --i) {
            if (freq[i] == i) {
                return i;
            }
        }

        return -1;
    }
};
