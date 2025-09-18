#include <bits/stdc++.h>
using namespace std;

class TaskManager {
public:
    // taskId -> {userId, priority}
    unordered_map<int, pair<int,int>> taskMap;
    
    // max-heap: {priority, taskId, userId}
    priority_queue<tuple<int,int,int>> pq;
    
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            taskMap[taskId] = {userId, priority};
            pq.emplace(priority, taskId, userId);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskMap[taskId] = {userId, priority};
        pq.emplace(priority, taskId, userId);
    }
    
    void edit(int taskId, int newPriority) {
        auto[userId, oldPriority] = taskMap[taskId];
        taskMap[taskId] = {userId, newPriority};
        pq.emplace(newPriority, taskId, userId); // push new version
    }
    
    void rmv(int taskId) {
        taskMap.erase(taskId); // lazy removal
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto [priority, taskId, userId] = pq.top();
            pq.pop();
            if (taskMap.count(taskId) && taskMap[taskId].second == priority) {
                taskMap.erase(taskId); // remove from active tasks
                return userId;
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
