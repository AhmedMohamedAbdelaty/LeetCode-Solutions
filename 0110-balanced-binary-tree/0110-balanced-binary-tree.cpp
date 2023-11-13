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
    unordered_map<TreeNode*, int> height;

    int get_height(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        if (height.count(root))
            return height[root];
        return height[root] = max(get_height(root->left), get_height(root->right)) + 1;
    }

public:
    bool isBalanced(TreeNode* root)
    {
        if (root == nullptr)
            return true;
        int left_height = get_height(root->left);
        int right_height = get_height(root->right);
        if (abs(left_height - right_height) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};