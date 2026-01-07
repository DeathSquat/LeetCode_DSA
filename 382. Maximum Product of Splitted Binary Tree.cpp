class Solution {
public:
    long long totalSum = 0;
    long long maxProd = 0;
    const int MOD = 1e9 + 7;

    // First DFS to calculate total sum
    long long getTotalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
    }

    // Second DFS to compute subtree sums and maximize product
    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long leftSum = dfs(root->left);
        long long rightSum = dfs(root->right);
        long long subSum = root->val + leftSum + rightSum;

        // Consider cutting above this subtree
        maxProd = max(maxProd, subSum * (totalSum - subSum));

        return subSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = getTotalSum(root);
        dfs(root);
        return maxProd % MOD;
    }
};
