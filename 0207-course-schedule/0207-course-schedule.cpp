class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> need(numCourses, 0);
        for (auto& p : prerequisites) {
            adj[p[0]].push_back(p[1]);
            need[p[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (need[i] == 0)
                q.push(i);
        int cnt = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cnt++;
            for (int v : adj[u])
                if (--need[v] == 0)
                    q.push(v);
        }
        return cnt == numCourses;
    }
};