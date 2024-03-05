class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal)
    {
        if (maxChoosableInteger >= desiredTotal)
            return true;
        if ((maxChoosableInteger * (maxChoosableInteger + 1)) / 2 < desiredTotal) // sum of n natural numbers is less than desiredTotal then it is impossible to win
            return false;
        vector<int> dp(1 << maxChoosableInteger, -1); // 2^maxChoosableInteger = number of states
        return canIWin(maxChoosableInteger, desiredTotal, 0, dp);
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal, int state, vector<int>& dp)
    {
        if (dp[state] != -1)
            return dp[state];
        for (int i = 0; i < maxChoosableInteger; i++) {
            if ((state & (1 << i)) == 0) {
                if (i + 1 >= desiredTotal || !canIWin(maxChoosableInteger, desiredTotal - (i + 1), state | (1 << i), dp)) {
                    dp[state] = 1; // if i+1 is greater than or equal to desiredTotal then I win, or if the next player loses then I win as well
                    return true;
                }
            }
        }
        dp[state] = 0;
        return false;
    }
};