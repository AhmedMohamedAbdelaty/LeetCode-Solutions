/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        return search(root, p, q);
    }

    TreeNode* search(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        // If the root is null or equal to either p or q, return the root
        if (!root || root == p || root == q)
            return root;

        // Recursively search for p and q in the left and right subtrees
        TreeNode* left = search(root->left, p, q);
        TreeNode* right = search(root->right, p, q);

        // If both p and q are found in different subtrees, the current root is the lowest common ancestor
        if (left && right)
            return root;

        // If only the left node is found, it is the lowest common ancestor (e.g., Example 2 in the problem description)
        if (left)
            return left;

        // If only the right node is found, it is the lowest common ancestor
        return right;
    }
};