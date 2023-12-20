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
    bool isValidBST(TreeNode* root)
    {
        return isValid(root);
    }
    bool isValid(TreeNode* root, long long mn = LONG_LONG_MIN, long long mx = LONG_LONG_MAX)
    {
        // go left, make sure every child is less than the root
        // go right, make sure every child is bigger than the root
        if (root == nullptr)
            return true;
        if (root->val <= mn || root->val >= mx) {
            return false;
        }
        return isValid(root->left, mn, root->val) && isValid(root->right, root->val, mx);
    }
};