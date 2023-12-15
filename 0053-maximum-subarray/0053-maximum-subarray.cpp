class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
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