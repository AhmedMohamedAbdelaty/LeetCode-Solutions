class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int mx = -1, ans = -1, n = prices.size();
        for (int i = n - 1; i >= 0; i--) {
            mx = max(mx, prices[i]);
            ans = max(ans, (mx - prices[i]));
        }
        return ans;
    }
};