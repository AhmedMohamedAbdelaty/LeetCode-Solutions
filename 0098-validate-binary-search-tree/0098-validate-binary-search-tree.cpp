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
typedef long long int ll;
class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        return isValidBST_Helper(root, LONG_LONG_MAX, LONG_LONG_MIN);
    }

    bool isValidBST_Helper(TreeNode* root, ll mx, ll mn)
    {
        if (root == nullptr)
            return true;

        if (root->val <= mn || root->val >= mx)
            return false;

        return isValidBST_Helper(root->left, root->val, mn) && isValidBST_Helper(root->right, mx, root->val);
    }
};