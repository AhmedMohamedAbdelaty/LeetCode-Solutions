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
    vector<int> t1, t2;
    void bfs(TreeNode* root, vector<int>& tree)
    {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                TreeNode* node = q.front();
                q.pop();
                tree.push_back(node ? node->val : 1e5);
                if (node) {
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        t1.clear();
        t2.clear();
        bfs(p, t1);
        bfs(q, t2);
        return t1 == t2;
    }
};