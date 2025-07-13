#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        // Sort both arrays
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        
        int i = 0; // pointer for players
        int j = 0; // pointer for trainers
        int matches = 0;

        // Try to match players and trainers greedily
        while (i < players.size() && j < trainers.size()) {
            if (players[i] <= trainers[j]) {
                // Valid match
                matches++;
                i++;
                j++;
            } else {
                // Current trainer can't train this player, try next trainer
                j++;
            }
        }

        return matches;
    }
};
