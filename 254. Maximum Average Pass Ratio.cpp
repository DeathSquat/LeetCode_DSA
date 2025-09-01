#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Lambda to calculate the gain in pass ratio if one more student is added
        auto gain = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        // Max heap storing (gain, pass, total)
        priority_queue<pair<double, pair<int,int>>> pq;

        // Initialize heap with each class
        for (auto &c : classes) {
            int pass = c[0], total = c[1];
            pq.push({gain(pass, total), {pass, total}});
        }

        // Distribute extra students
        while (extraStudents--) {
            auto top = pq.top(); pq.pop();
            int pass = top.second.first;
            int total = top.second.second;
            pass++, total++;
            pq.push({gain(pass, total), {pass, total}});
        }

        // Calculate final average
        double sum = 0.0;
        while (!pq.empty()) {
            auto [_, pr] = pq.top(); pq.pop();
            sum += (double)pr.first / pr.second;
        }
        return sum / classes.size();
    }
};
