class Solution {
    vector<vector<int>> dp;
public:
    int change(int amount, vector<int>& coins)
    {
        dp.resize(coins.size() + 1, vector<int>(amount + 1, -1));
        return solve(coins, coins.size(), amount);
    }
    int solve(vector<int>& coins, int n, int amount)
    {
        if (amount == 0)
            return 1;
        if (n == 0)
            return 0;
        if (dp[n][amount] != -1)
            return dp[n][amount];
        if (coins[n - 1] <= amount)
            return dp[n][amount] = solve(coins, n, amount - coins[n - 1]) + solve(coins, n - 1, amount);
        return dp[n][amount] = solve(coins, n - 1, amount);
    }
};