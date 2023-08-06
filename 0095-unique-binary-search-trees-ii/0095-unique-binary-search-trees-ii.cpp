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
    vector<TreeNode*> generateTrees(int n)
    {
        vector<TreeNode*> ans;
        if (n == 0)
            return ans;
        return solve(1, n);
    }
    vector<TreeNode*> solve(int l, int r)
    {
        vector<TreeNode*> ans;
        if (l > r) {
            ans.push_back(nullptr);
            return ans;
        }
        for (int i = l; i <= r; i++) {
            vector<TreeNode*> left = solve(l, i - 1);
            vector<TreeNode*> right = solve(i + 1, r);
            for (auto l : left) {
                for (auto r : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};