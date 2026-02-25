class Solution {
public:
    static int countBits(int x) {
        return __builtin_popcount(x);  // Counts number of 1s in binary
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int bitsA = __builtin_popcount(a);
            int bitsB = __builtin_popcount(b);
            
            if (bitsA == bitsB)
                return a < b;   // If same number of 1s, sort by value
            return bitsA < bitsB; // Otherwise sort by number of 1s
        });
        
        return arr;
    }
};
