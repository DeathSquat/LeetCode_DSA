class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int operations = target[0]; // The first element is directly the first operation needed
        for (int i = 1; i < target.size(); ++i) {
            if (target[i] > target[i-1]) {
                operations += target[i] - target[i-1]; // Add the positive difference
            }
        }
        return operations;
    }
};
