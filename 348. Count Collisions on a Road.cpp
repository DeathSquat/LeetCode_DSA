class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int left = 0, right = n - 1;

        // Skip leading 'L'
        while (left < n && directions[left] == 'L') 
            left++;

        // Skip trailing 'R'
        while (right >= 0 && directions[right] == 'R') 
            right--;

        int collisions = 0;

        // Count collisions in the remaining middle segment
        for (int i = left; i <= right; i++) {
            if (directions[i] != 'S')  // 'R' or 'L' must collide
                collisions++;
        }

        return collisions;
    }
};
