class Solution {
    vector<vector<int>> dp;

public:
    int minimumDeleteSum(string s1, string s2)
    {
        int n = s1.size(), m = s2.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return solve(0, 0, s1, s2);
    }
    int solve(int i, int j, string& s1, string& s2)
    {
        if (i == s1.size() && j == s2.size())
            return 0;
        if (i == s1.size()) {
            int ans = 0;
            for (int k = j; k < s2.size(); k++)
                ans += s2[k];
            return ans;
        }
        if (j == s2.size()) {
            int ans = 0;
            for (int k = i; k < s1.size(); k++)
                ans += s1[k];
            return ans;
        }
        int& ans = dp[i][j];
        if (~ans)
            return ans;
        ans = 0;
        if (s1[i] == s2[j])
            ans = solve(i + 1, j + 1, s1, s2);
        else {
            ans = min(solve(i + 1, j, s1, s2) + s1[i], solve(i, j + 1, s1, s2) + s2[j]);
        }
        return ans;
    }
};