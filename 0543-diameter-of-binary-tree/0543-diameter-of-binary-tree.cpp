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
        calc_height(root);
        return mx;
    }
    int calc_height(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        int left = calc_height(root->left);
        int right = calc_height(root->right);
        mx = max(mx, left + right);
        return max(left, right) + 1;
    }
};