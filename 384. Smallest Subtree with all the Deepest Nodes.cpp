class Solution {
public:
    // Returns {deepestDepth, subtreeRootContainingAllDeepest}
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (!root) return {0, nullptr};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left.first > right.first) {
            return {left.first + 1, left.second};
        } 
        else if (right.first > left.first) {
            return {right.first + 1, right.second};
        } 
        else {
            // Both sides have deepest nodes at same depth
            return {left.first + 1, root};
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};
