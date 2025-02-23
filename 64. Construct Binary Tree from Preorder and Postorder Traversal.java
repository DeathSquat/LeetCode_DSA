/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int preIndex = 0;
    private int postIndex = 0;
    
    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        TreeNode root = new TreeNode(preorder[preIndex++]); // Create root node
        
        // If the root is not the last node in postorder, construct left subtree
        if (root.val != postorder[postIndex]) {
            root.left = constructFromPrePost(preorder, postorder);
        }
        
        // If the root is not the last node in postorder, construct right subtree
        if (root.val != postorder[postIndex]) {
            root.right = constructFromPrePost(preorder, postorder);
        }
        
        postIndex++; // Move to next postorder index after constructing the tree
        return root;
    }
}
