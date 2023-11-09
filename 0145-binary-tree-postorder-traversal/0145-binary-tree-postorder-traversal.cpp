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
private:
    vector<int> ans;
    void postorder(TreeNode* root)
    {
        if (root->left)
            postorder(root->left);
        if (root->right)
            postorder(root->right);
        ans.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        if (root)
            postorder(root);
        return ans;
    }
};