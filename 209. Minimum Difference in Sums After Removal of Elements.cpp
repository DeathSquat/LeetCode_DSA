class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;
        int totalSize = nums.size();
        
        // left[i]: min sum of picking n smallest from nums[0..i]
        priority_queue<int> maxHeap;
        vector<long long> left(totalSize, 0);
        long long leftSum = 0;
        
        for (int i = 0; i < n * 2; ++i) {
            maxHeap.push(nums[i]);
            leftSum += nums[i];
            if (maxHeap.size() > n) {
                leftSum -= maxHeap.top();
                maxHeap.pop();
            }
            if (maxHeap.size() == n) {
                left[i] = leftSum;
            }
        }
        
        // right[i]: max sum of picking n largest from nums[i..]
        priority_queue<int, vector<int>, greater<int>> minHeap;
        vector<long long> right(totalSize, 0);
        long long rightSum = 0;
        
        for (int i = totalSize - 1; i >= n; --i) {
            minHeap.push(nums[i]);
            rightSum += nums[i];
            if (minHeap.size() > n) {
                rightSum -= minHeap.top();
                minHeap.pop();
            }
            if (minHeap.size() == n) {
                right[i] = rightSum;
            }
        }
        
        long long result = LLONG_MAX;
        for (int i = n - 1; i < n * 2; ++i) {
            result = min(result, left[i] - right[i + 1]);
        }
        
        return result;
    }
};
