#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballToColor; // Stores ball -> color mapping
        unordered_set<int> distinctColors;  // Stores unique colors
        vector<int> result;

        for (const auto& query : queries) {
            int ball = query[0];
            int color = query[1];

            // If the ball already has a color, remove the old one from distinctColors if needed
            if (ballToColor.count(ball)) {
                int oldColor = ballToColor[ball];
                if (oldColor != color) {
                    ballToColor[ball] = color; // Update to new color

                    // Check if the old color is still present in any ball
                    bool found = false;
                    for (auto& pair : ballToColor) {
                        if (pair.second == oldColor) {
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        distinctColors.erase(oldColor);
                    }
                }
            } else {
                ballToColor[ball] = color; // Assign new color
            }

            distinctColors.insert(color); // Add the new color
            result.push_back(distinctColors.size()); // Store count of distinct colors
        }

        return result;
    }
};
