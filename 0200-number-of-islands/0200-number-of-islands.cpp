class Solution {
    vector<vector<int>> vis;
    int n, m;
    bool valid(int x, int y, vector<vector<char>>& grid)
    {
        return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '1';
    }

public:
    int numIslands(vector<vector<char>>& grid)
    {
        vis.assign(300 + 5, vector<int>(300 + 5, 0));
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && vis[i][j] == 0) {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid, int x, int y)
    {
        vis[x][y] = 1;
        // org : x,y

        // go left x+1, y
        if (valid(x + 1, y, grid) && !vis[x + 1][y]) {
            dfs(grid, x + 1, y);
        }
        // go right x-1, y
        if (valid(x - 1, y, grid) && !vis[x - 1][y]) {
            dfs(grid, x - 1, y);
        }
        // go up x, y+1
        if (valid(x, y + 1, grid) && !vis[x][y + 1]) {
            dfs(grid, x, y + 1);
        }
        // go down x, y-1
        if (valid(x, y - 1, grid) && !vis[x][y] - 1) {
            dfs(grid, x, y - 1);
        }
    }
};