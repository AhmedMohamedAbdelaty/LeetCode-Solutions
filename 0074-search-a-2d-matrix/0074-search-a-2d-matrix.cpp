class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix.front().size();
        int l = 0, r = n * m - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int x = mid / m, y = mid % m;
            if (matrix[x][y] == target)
                return true;
            if (matrix[x][y] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
};