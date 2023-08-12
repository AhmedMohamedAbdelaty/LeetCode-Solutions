class Solution {
    vector<vector<int>> dp;

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        dp.resize(n, vector<int>(m, -1));
        return solve(obstacleGrid, 0, 0, n, m);
    }
    int solve(vector<vector<int>>& obstacleGrid, int i, int j, int n, int m)
    {
        if (i == n - 1 && j == m - 1) {
            return !obstacleGrid[i][j];
        }
        if (i >= n || j >= m || obstacleGrid[i][j]) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        return dp[i][j] = solve(obstacleGrid, i + 1, j, n, m) + solve(obstacleGrid, i, j + 1, n, m);
    }
};