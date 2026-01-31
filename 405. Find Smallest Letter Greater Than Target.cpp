class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left = 0, right = letters.size() - 1;
        char ans = letters[0]; // default for wrap-around case
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (letters[mid] > target) {
                ans = letters[mid];
                right = mid - 1;  // try to find a smaller valid letter
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};
