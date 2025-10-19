#include <string>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> visited;
        queue<string> q;
        string result = s;

        q.push(s);
        visited.insert(s);

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            // Update result if current string is smaller
            if (curr < result) {
                result = curr;
            }

            // Operation 1: Add 'a' to all odd indices
            string addStr = curr;
            for (int i = 1; i < addStr.size(); i += 2) {
                addStr[i] = ((addStr[i] - '0' + a) % 10) + '0';
            }
            if (visited.find(addStr) == visited.end()) {
                visited.insert(addStr);
                q.push(addStr);
            }

            // Operation 2: Rotate right by 'b'
            string rotated = curr.substr(curr.size() - b) + curr.substr(0, curr.size() - b);
            if (visited.find(rotated) == visited.end()) {
                visited.insert(rotated);
                q.push(rotated);
            }
        }

        return result;
    }
};
