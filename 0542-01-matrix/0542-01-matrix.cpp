class Solution {
    int n, m;
    vector<vector<bool>> vis;
    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { -1, 1, 0, 0 };

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        n = mat.size();
        m = mat[0].size();
        vis.resize(n, vector<bool>(m, false));
        vector<vector<int>> ans(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({ i, j });
                    vis[i][j] = true;
                }
            }
        }
        int dist = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto p = q.front(); // {x, y}
                q.pop();
                int x = p.first, y = p.second;
                ans[x][y] = dist;
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                        vis[nx][ny] = true;
                        q.push({ nx, ny });
                    }
                }
            }
            dist++;
        }
        return ans;
    }
};