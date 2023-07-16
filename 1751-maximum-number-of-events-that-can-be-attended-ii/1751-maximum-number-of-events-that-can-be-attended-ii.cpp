class Solution {
    vector<vector<int>> dp;

public:
    int maxValue(vector<vector<int>>& events, int k)
    {
        sort(events.begin(), events.end());
        int n = events.size();
        dp.resize(n + 1, vector<int>(k + 1, -1));
        return solve(events, 0, k);
    }
    int solve(vector<vector<int>>& events, int idx, int k)
    {
        if (idx == events.size() || k == 0)
            return 0;
        int& ret = dp[idx][k];
        if (~ret)
            return ret;
        int ans = solve(events, idx + 1, k);
        int nxt = lower_bound(events.begin(), events.end(), vector<int> { events[idx][1] + 1, 0, 0 }) - events.begin();
        ans = max(ans, events[idx][2] + solve(events, nxt, k - 1));
        return ret = ans;
    }
};