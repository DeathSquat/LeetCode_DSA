class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;                      // left pointer
        int right = height.size() - 1;     // right pointer
        int maxWater = 0;                  // to store the maximum area
        
        while (left < right) {
            // Calculate the width between the two lines
            int width = right - left;
            
            // Height is limited by the shorter line
            int minHeight = min(height[left], height[right]);
            
            // Calculate the area and update maxWater if larger
            int currentArea = width * minHeight;
            maxWater = max(maxWater, currentArea);
            
            // Move the pointer pointing to the shorter line inward
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        
        return maxWater;
    }
};
