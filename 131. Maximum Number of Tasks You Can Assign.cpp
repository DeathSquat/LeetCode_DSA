#include <vector>
#include <algorithm>
#include <deque>
#include <set>
using namespace std;

class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 0, right = min((int)tasks.size(), (int)workers.size());
        int result = 0;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }

private:
    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> available(workers.end() - k, workers.end());
        deque<int> task_deque(tasks.begin(), tasks.begin() + k);
        int pillsLeft = pills;

        while (!task_deque.empty()) {
            int task = task_deque.back();  // hardest remaining task
            task_deque.pop_back();

            // Try to assign without pill
            auto it = available.lower_bound(task);
            if (it != available.end()) {
                available.erase(it);
                continue;
            }

            // Try to assign with pill
            if (pillsLeft == 0) return false;
            it = available.lower_bound(task - strength);
            if (it == available.end()) return false;
            available.erase(it);
            pillsLeft--;
        }

        return true;
    }
};
