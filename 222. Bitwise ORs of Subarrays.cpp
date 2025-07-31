#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> current, next;

        for (int num : arr) {
            next.clear();
            next.insert(num);  // subarray of just the current number

            // Extend all ORs from previous step
            for (int val : current) {
                next.insert(val | num);
            }

            // Add all values from this step to the global result
            for (int val : next) {
                result.insert(val);
            }

            // Move next to current for next iteration
            current = next;
        }

        return result.size();
    }
};
