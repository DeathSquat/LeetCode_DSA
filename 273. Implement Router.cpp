#include <bits/stdc++.h>
using namespace std;

class Router {
    int memoryLimit;
    queue<array<int,3>> q; // store packets in FIFO order: [source, destination, timestamp]
    unordered_set<string> seen; // to detect duplicates
    unordered_map<int, vector<int>> destMap; // destination -> sorted list of timestamps

    string encode(int source, int destination, int timestamp) {
        return to_string(source) + "#" + to_string(destination) + "#" + to_string(timestamp);
    }

public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string key = encode(source, destination, timestamp);
        if (seen.count(key)) return false; // duplicate

        // If memory full, remove oldest
        if ((int)q.size() == memoryLimit) {
            auto old = q.front();
            q.pop();
            string oldKey = encode(old[0], old[1], old[2]);
            seen.erase(oldKey);

            // remove from destMap (timestamps are increasing, so oldest is at front)
            auto &vec = destMap[old[1]];
            // since timestamps are increasing and erased oldest, we erase the first element
            if (!vec.empty() && vec.front() == old[2]) {
                vec.erase(vec.begin());
            } else {
                // fallback: binary search erase
                auto it = lower_bound(vec.begin(), vec.end(), old[2]);
                if (it != vec.end() && *it == old[2]) vec.erase(it);
            }
        }

        q.push({source, destination, timestamp});
        seen.insert(key);
        destMap[destination].push_back(timestamp); // timestamps are non-decreasing
        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty()) return {};
        auto p = q.front();
        q.pop();
        string key = encode(p[0], p[1], p[2]);
        seen.erase(key);

        // remove timestamp from destMap
        auto &vec = destMap[p[1]];
        if (!vec.empty() && vec.front() == p[2]) {
            vec.erase(vec.begin());
        } else {
            auto it = lower_bound(vec.begin(), vec.end(), p[2]);
            if (it != vec.end() && *it == p[2]) vec.erase(it);
        }

        return {p[0], p[1], p[2]};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if (!destMap.count(destination)) return 0;
        auto &vec = destMap[destination];
        auto low = lower_bound(vec.begin(), vec.end(), startTime);
        auto high = upper_bound(vec.begin(), vec.end(), endTime);
        return high - low;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
