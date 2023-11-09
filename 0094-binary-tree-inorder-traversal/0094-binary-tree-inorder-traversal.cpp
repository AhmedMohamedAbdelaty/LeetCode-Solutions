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
    void inorder(TreeNode* root)
    {
        if (root->left)
            inorder(root->left);
        ans.push_back(root->val);
        if (root->right)
            inorder(root->right);
    }

public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        if (root)
            inorder(root);
        return ans;
    }
};