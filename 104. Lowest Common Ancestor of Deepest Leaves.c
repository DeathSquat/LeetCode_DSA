// Define a struct to return both depth and the node
struct Result {
    int depth;
    struct TreeNode* node;
};

struct Result dfs(struct TreeNode* root) {
    if (root == NULL) {
        return (struct Result){0, NULL};
    }

    struct Result left = dfs(root->left);
    struct Result right = dfs(root->right);

    if (left.depth > right.depth) {
        return (struct Result){left.depth + 1, left.node};
    } else if (right.depth > left.depth) {
        return (struct Result){right.depth + 1, right.node};
    } else {
        // If both sides are equal, current root is the LCA
        return (struct Result){left.depth + 1, root};
    }
}

struct TreeNode* lcaDeepestLeaves(struct TreeNode* root) {
    return dfs(root).node;
}
