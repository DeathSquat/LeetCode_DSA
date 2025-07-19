class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Sort folders lexicographically
        sort(folder.begin(), folder.end());
        
        vector<string> result;
        string prev = "";  // To keep track of the last added top-level folder
        
        for (const string& f : folder) {
            // If the current folder is not a subfolder of the last added folder
            // Note: prev + '/' ensures we only skip true subfolders
            if (prev.empty() || f.find(prev + "/") != 0) {
                result.push_back(f);
                prev = f;
            }
        }
        
        return result;
    }
};
