/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int> ans;
    int kk;

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        unordered_map<TreeNode*, TreeNode*> parent; // node, parent
        dfs(root, NULL, parent);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;
        q.push(target);
        vis.insert(target);
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            if (level == k) {
                while (!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }
            while (sz--) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left && !vis.count(node->left)) {
                    q.push(node->left);
                    vis.insert(node->left);
                }
                if (node->right && !vis.count(node->right)) {
                    q.push(node->right);
                    vis.insert(node->right);
                }
                if (parent[node] && !vis.count(parent[node])) {
                    q.push(parent[node]);
                    vis.insert(parent[node]);
                }
            }
            level++;
        }
                return ans;
    }
    void dfs(TreeNode* root, TreeNode* par, unordered_map<TreeNode*, TreeNode*>& parent)
    {
        if (root == NULL)
            return;
        parent[root] = par;
        dfs(root->left, root, parent);
        dfs(root->right, root, parent);
    }

};