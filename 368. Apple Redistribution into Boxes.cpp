class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        // Step 1: Calculate the total number of apples
        int totalApples = 0;
        for (int i = 0; i < apple.size(); i++) {
            totalApples += apple[i];
        }
        
        // Step 2: Sort the boxes based on their capacity in descending order
        sort(capacity.begin(), capacity.end(), greater<int>());
        
        // Step 3: Use a greedy approach to pick the largest boxes
        int currentCapacity = 0;
        int boxCount = 0;
        
        for (int i = 0; i < capacity.size(); i++) {
            currentCapacity += capacity[i];
            boxCount++;
            
            // If we have enough capacity to hold all apples, stop
            if (currentCapacity >= totalApples) {
                break;
            }
        }
        
        return boxCount;
    }
};
