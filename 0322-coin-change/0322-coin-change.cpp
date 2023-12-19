class Solution {
    vector<vector<int>> mem;

public:
    int coinChange(vector<int>& coins, int amount)
    {
        mem.assign(coins.size() + 1, vector<int>(amount + 1, -1));
        int ans = countMemo(coins, amount, 0);
        return ans == 2147483646? -1: ans;
    }
    int countMemo(vector<int>& coins, int rem, int idx)
    {
        if (rem == 0)
            return 0;
        if (idx >= coins.size() || rem < 0)
            return INT_MAX-1;

        if (~mem[idx][rem]) {
            return mem[idx][rem];
        }

        int ans = -1;
        if (coins[idx] > rem) {
            int dontTake = countMemo(coins, rem, idx + 1);
            ans = dontTake;
            mem[idx][rem] = ans;
        } else {
            int takeCoin = 1 + countMemo(coins, rem - coins[idx], idx);
            int dontTake = countMemo(coins, rem, idx + 1);
            ans = min(takeCoin, dontTake);
            mem[idx][rem] = ans;
        }
        return mem[idx][rem];
    }
};