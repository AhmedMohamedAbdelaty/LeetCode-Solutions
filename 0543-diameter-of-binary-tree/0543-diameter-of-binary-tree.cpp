/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int mx = 0;

public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        mx = max(mx, l + r);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return mx;
    }
    int depth(TreeNode* root)
    {
        if (root == NULL)
            return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        return max(l, r) + 1;
    }
};