class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        int n = coins.size();
        sort(coins.begin(), coins.end());
        for (int value = 1; value <= amount; value++) {
            for (int i = 0; i < n; i++) {
                if (coins[i] > value) {
                    break;
                }
                if (dp[value - coins[i]] != INT_MAX) {
                    dp[value] = min(dp[value], 1 + dp[value - coins[i]]);
                }
            }
        }
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};