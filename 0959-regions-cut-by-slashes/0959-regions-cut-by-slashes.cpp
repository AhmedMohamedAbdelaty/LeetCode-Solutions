#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
    int ans = 0;
    vector<vector<int>> scale(vector<string>& grid) {
        vector<vector<int>> res(grid.size() * 3,
                                vector<int>(grid[0].size() * 3, 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                fill(res, i, j, grid[i][j]);
            }
        }
        return res;
    }
    void fill(vector<vector<int>>& res, int i, int j, char ch) {
        if (ch == '/') {
            res[i * 3][j * 3 + 2] = 1;
            res[i * 3 + 1][j * 3 + 1] = 1;
            res[i * 3 + 2][j * 3] = 1;
        } else if (ch == '\\') {
            res[i * 3][j * 3] = 1;
            res[i * 3 + 1][j * 3 + 1] = 1;
            res[i * 3 + 2][j * 3 + 2] = 1;
        }
    }
    void countRegions(vector<vector<int>>& scaled, int i, int j) {
        if (i < 0 || i >= scaled.size() || j < 0 || j >= scaled[i].size() ||
            scaled[i][j] == 1) {
            return;
        }
        scaled[i][j] = 1;
        countRegions(scaled, i + 1, j);
        countRegions(scaled, i - 1, j);
        countRegions(scaled, i, j + 1);
        countRegions(scaled, i, j - 1);
    }

public:
    int regionsBySlashes(vector<string>& grid) {
        // For each cell, scale it to 3x3
        vector<vector<int>> scaled = scale(grid);
        for (int i = 0; i < scaled.size(); i++) {
            for (int j = 0; j < scaled[i].size(); j++) {
                if (scaled[i][j] == 0) {
                    ans++;
                    countRegions(scaled, i, j);
                }
            }
        }
        return ans;
    }
};
