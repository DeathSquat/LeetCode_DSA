#include <vector>
#include <numeric> // for gcd
using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;

        for (int num : nums) {
            // Start with current number
            int cur = num;

            // Merge backwards while non-coprime
            while (!st.empty()) {
                int g = gcd(st.back(), cur);
                if (g == 1) break; // coprime, stop merging

                // Replace with LCM
                cur = (1LL * st.back() * cur) / g;
                st.pop_back();
            }

            st.push_back(cur);
        }

        return st;
    }
};
