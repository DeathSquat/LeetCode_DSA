#include <queue>
#include <vector>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> minHeap(nums.begin(), nums.end());
        int operations = 0;
        
        while (minHeap.top() < k) {
            long long x = minHeap.top(); minHeap.pop();
            long long y = minHeap.top(); minHeap.pop();
            
            long long newElement = x * 2 + y; // Use long long to avoid overflow
            minHeap.push(newElement);
            operations++;
        }
        
        return operations;
    }
};
