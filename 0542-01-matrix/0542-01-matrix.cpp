class Solution {
    int n, m;

    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { -1, 1, 0, 0 };

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({ i, j });
                    ans[i][j] = 0;
                }
            }
        }
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && ans[nx][ny] == -1) {
                    ans[nx][ny] = ans[x][y] + 1;
                    q.push({ nx, ny });
                }
            }
        }
        return ans;
    }
};