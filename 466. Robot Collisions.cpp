class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        // Store {position, health, direction, original index}
        vector<tuple<int,int,char,int>> robots;
        for(int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }
        
        // Sort by position
        sort(robots.begin(), robots.end());
        
        stack<int> st; // store indices in robots vector
        vector<int> currHealth(n);
        
        for(int i = 0; i < n; i++) {
            currHealth[i] = get<1>(robots[i]);
        }
        
        for(int i = 0; i < n; i++) {
            char dir = get<2>(robots[i]);
            
            if(dir == 'R') {
                st.push(i);
            } else {
                // dir == 'L'
                while(!st.empty() && currHealth[i] > 0) {
                    int j = st.top();
                    
                    if(currHealth[j] < currHealth[i]) {
                        // stack robot dies
                        st.pop();
                        currHealth[i]--;
                        currHealth[j] = 0;
                    } 
                    else if(currHealth[j] > currHealth[i]) {
                        // current robot dies
                        currHealth[j]--;
                        currHealth[i] = 0;
                    } 
                    else {
                        // both die
                        currHealth[j] = 0;
                        currHealth[i] = 0;
                        st.pop();
                    }
                }
            }
        }
        
        // Prepare result in original order
        vector<int> result(n, 0);
        for(int i = 0; i < n; i++) {
            int originalIndex = get<3>(robots[i]);
            result[originalIndex] = currHealth[i];
        }
        
        // Filter only alive robots
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(result[i] > 0) ans.push_back(result[i]);
        }
        
        return ans;
    }
};
