#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sort events by their start day
        sort(events.begin(), events.end());
        
        // Min-heap to store end days
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        int day = 0, i = 0, n = events.size(), result = 0;
        
        // Go through days while there are unprocessed events or heap is not empty
        while (i < n || !minHeap.empty()) {
            if (minHeap.empty()) {
                // Jump to the start day of the next event
                day = events[i][0];
            }

            // Add all events starting today into the heap
            while (i < n && events[i][0] <= day) {
                minHeap.push(events[i][1]);
                i++;
            }

            // Remove all events that have already expired
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

            // Attend the event that ends the earliest
            if (!minHeap.empty()) {
                minHeap.pop();  // Attend one event
                result++;
                day++;  // Move to next day
            }
        }
        
        return result;
    }
};
