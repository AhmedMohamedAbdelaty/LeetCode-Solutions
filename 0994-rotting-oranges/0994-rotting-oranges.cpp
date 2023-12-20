class Solution {
    int n, m;
    bool valid(int x, int y)
    {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }

public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        queue<pair<int, int>> rot;
        vector<vector<int>> vis(15, vector<int>(15, 0));
        n = grid.size(),
        m = grid[0].size();
        bool freshExists = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    rot.push({ i, j });
                }
                if (grid[i][j] == 1) {
                    freshExists = true;
                }
            }
        }
        if (!freshExists) // no fresh orange to rot
            return 0;
        int ans = 0;
        while (!rot.empty()) {
            int sz = rot.size();
            while (sz--) {
                auto top = rot.front();
                int x = top.first, y = top.second;
                rot.pop();
                // org: x, y
                // new point must be valid and not visited and not empty
                // go right: x+1, y
                if (valid(x + 1, y) && !vis[x + 1][y] && grid[x + 1][y] != 0 && grid[x + 1][y] != 2) {
                    rot.push({ x + 1, y });
                    vis[x + 1][y] = 1;
                    grid[x + 1][y] = 2;
                }
                // go left: x-1, y
                if (valid(x - 1, y) && !vis[x - 1][y] && grid[x - 1][y] != 0 && grid[x - 1][y] != 2) {
                    rot.push({ x - 1, y });
                    vis[x - 1][y] = 1;
                    grid[x - 1][y] = 2;
                }
                // go up: x, y+1
                if (valid(x, y + 1) && !vis[x][y + 1] && grid[x][y + 1] != 0 && grid[x][y + 1] != 2) {
                    rot.push({ x, y + 1 });
                    vis[x][y + 1] = 1;
                    grid[x][y + 1] = 2;
                }
                // go down: x, y-1
                if (valid(x, y - 1) && !vis[x][y - 1] && grid[x][y - 1] != 0 && grid[x][y - 1] != 2) {
                    rot.push({ x, y - 1 });
                    vis[x][y - 1] = 1;
                    grid[x][y - 1] = 2;
                }
            }
            ans++;
        }
        // check if any fresh orange is left
        bool fresh = false;
        for (auto& row : grid) {
            for (auto& cell : row) {
                if (cell == 1) {
                    fresh = true;
                    return -1;
                }
            }
        }
        return ans - 1;
    }
};