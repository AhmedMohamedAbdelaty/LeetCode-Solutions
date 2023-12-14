class Solution {
    int n, m, oldColor, newColor;
    bool ok(int i, int j, int n, int m)
    {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    void dfs(vector<vector<int>>& image, int i, int j)
    {
        image[i][j] = newColor;
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k], y = j + dy[k];
            if (ok(x, y, n, m) && image[x][y] == oldColor)
                dfs(image, x, y);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        n = image.size(), m = image[0].size();
        oldColor = image[sr][sc];
        if (oldColor == color)
            return image;
        newColor = color;
        dfs(image, sr, sc);
        return image;
    }
};