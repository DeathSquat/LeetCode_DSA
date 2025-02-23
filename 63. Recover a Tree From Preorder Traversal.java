import java.util.Stack;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public TreeNode recoverFromPreorder(String traversal) {
        Stack<TreeNode> stack = new Stack<>();
        int i = 0;

        while (i < traversal.length()) {
            int depth = 0;
            
            // Count the number of dashes (depth level)
            while (i < traversal.length() && traversal.charAt(i) == '-') {
                depth++;
                i++;
            }
            
            // Extract the node value
            int value = 0;
            while (i < traversal.length() && Character.isDigit(traversal.charAt(i))) {
                value = value * 10 + (traversal.charAt(i) - '0');
                i++;
            }
            
            // Create a new node
            TreeNode node = new TreeNode(value);
            
            // If stack size > depth, pop to correct parent level
            while (stack.size() > depth) {
                stack.pop();
            }
            
            // Attach node as left or right child
            if (!stack.isEmpty()) {
                if (stack.peek().left == null) {
                    stack.peek().left = node;
                } else {
                    stack.peek().right = node;
                }
            }
            
            // Push the current node to the stack
            stack.push(node);
        }
        
        // The root is the first node added to the stack
        while (stack.size() > 1) {
            stack.pop();
        }
        
        return stack.pop();
    }
}
