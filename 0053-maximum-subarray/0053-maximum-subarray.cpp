class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
            ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int cur = 0, ans = INT_MIN, n = nums.size();
        int l = 0, r = 0;
        while (r < n) {
            cur += nums[r];
            ans = max(ans, cur);
            if (cur < 0) {
                cur = 0;
                l = r + 1;
            }
            r++;
        }
        return ans;
    }
};