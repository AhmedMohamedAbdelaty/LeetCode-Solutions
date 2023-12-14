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
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (root == NULL)
            return NULL;
        TreeNode* leftTemp = root->left;
        TreeNode* rightTemp = root->right;
        root->left = invertTree(rightTemp);
        root->right = invertTree(leftTemp);
        return root;
    }
};