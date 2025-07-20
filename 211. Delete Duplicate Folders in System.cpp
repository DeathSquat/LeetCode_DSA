class Solution {
public:
    struct TrieNode {
        map<string, TrieNode*> children;
        bool isDeleted = false;
    };

    TrieNode* root = new TrieNode();
    unordered_map<string, vector<TrieNode*>> subtrees;

    void insert(vector<string>& path) {
        TrieNode* node = root;
        for (string& folder : path) {
            if (!node->children.count(folder))
                node->children[folder] = new TrieNode();
            node = node->children[folder];
        }
    }

    string serialize(TrieNode* node) {
        if (node->children.empty())
            return "";

        vector<pair<string, string>> serializedChildren;
        for (auto& [name, child] : node->children) {
            string sub = serialize(child);
            serializedChildren.push_back({name, sub});
        }

        sort(serializedChildren.begin(), serializedChildren.end());

        string key;
        for (auto& [name, sub] : serializedChildren) {
            key += "(" + name + sub + ")";
        }

        subtrees[key].push_back(node);
        return key;
    }

    void markDeleted() {
        for (auto& [key, nodes] : subtrees) {
            if (nodes.size() > 1) {
                for (TrieNode* node : nodes)
                    node->isDeleted = true;
            }
        }
    }

    void collect(TrieNode* node, vector<string>& path, vector<vector<string>>& result) {
        if (node->isDeleted)
            return;

        if (!path.empty())
            result.push_back(path);

        for (auto& [name, child] : node->children) {
            path.push_back(name);
            collect(child, path, result);
            path.pop_back();
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        // Step 1: Build Trie
        for (auto& path : paths) {
            insert(path);
        }

        // Step 2: Serialize subtrees
        serialize(root);

        // Step 3: Mark duplicates
        markDeleted();

        // Step 4: Collect result
        vector<vector<string>> result;
        vector<string> path;
        collect(root, path, result);

        return result;
    }
};
