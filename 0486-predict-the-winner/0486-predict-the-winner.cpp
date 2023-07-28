class Solution {

public:
    bool PredictTheWinner(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int sum = accumulate(nums.begin(),nums.end(), 0LL);
        int a = solve(0, n - 1, nums, dp);
        return a >= sum - a;
    }
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp)
    {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int a = nums[i] + min(solve(i + 2, j, nums, dp), solve(i + 1, j - 1, nums, dp));
        int b = nums[j] + min(solve(i + 1, j - 1, nums, dp), solve(i, j - 2, nums, dp));
        return dp[i][j] = max(a, b);
    }
};