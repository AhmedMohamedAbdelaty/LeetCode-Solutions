class Solution {
    vector<vector<int>> adj;

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        int n = graph.size();
        adj.resize(n);
        vector<int> in(n);
        for (int i = 0; i < n; i++) {
            for (auto& x : graph[i]) {
                adj[x].push_back(i);
                in[i]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for (auto& v : adj[u]) {
                in[v]--;
                if (in[v] == 0)
                    q.push(v);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};