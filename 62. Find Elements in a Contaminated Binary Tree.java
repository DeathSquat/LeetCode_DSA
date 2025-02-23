import java.util.HashSet;

class FindElements {
    private HashSet<Integer> values;

    public FindElements(TreeNode root) {
        values = new HashSet<>();
        recoverTree(root, 0);
    }

    private void recoverTree(TreeNode node, int val) {
        if (node == null) return;
        node.val = val;
        values.add(val);
        recoverTree(node.left, 2 * val + 1);
        recoverTree(node.right, 2 * val + 2);
    }

    public boolean find(int target) {
        return values.contains(target);
    }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * boolean param_1 = obj.find(target);
 */
