#include <vector>
#include <unordered_map>
using namespace std;

class FindSumPairs {
private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freqMap2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num : nums2) {
            freqMap2[num]++;
        }
    }

    void add(int index, int val) {
        int oldVal = nums2[index];
        freqMap2[oldVal]--;
        if (freqMap2[oldVal] == 0) {
            freqMap2.erase(oldVal);
        }

        nums2[index] += val;
        freqMap2[nums2[index]]++;
    }

    int count(int tot) {
        int result = 0;
        for (int num1 : nums1) {
            int target = tot - num1;
            if (freqMap2.count(target)) {
                result += freqMap2[target];
            }
        }
        return result;
    }
};
