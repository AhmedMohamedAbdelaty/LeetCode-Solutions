class Solution {
    int n, m, fresh = 0;
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    bool valid(int i, int j)
    {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    int bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q)
    {
        int time = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) { // a second has passed
                auto [i, j] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (valid(x, y) && grid[x][y] == 1) {
						grid[x][y] = 2;
						q.push({ x, y });
						fresh--;
                    }
                }
            }
			if (!q.empty())
				time++;
        }
		return fresh == 0 ? time : -1;
    }

public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        n = grid.size();
        m = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 2)
                    q.push({ i, j });
                else if (grid[i][j] == 1)
                    fresh++;
        return bfs(grid, q);
    }
};