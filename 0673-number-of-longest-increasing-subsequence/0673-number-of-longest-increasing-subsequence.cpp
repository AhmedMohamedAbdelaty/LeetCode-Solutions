class Solution {
public:
    int findNumberOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> lis(n, 1), cnt(n, 1);
        int mx = 1;
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--)
                if (nums[i] > nums[j]) {
                    if (lis[i] < lis[j] + 1) {
                        lis[i] = lis[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (lis[i] == lis[j] + 1) {
                        cnt[i] += cnt[j];
                    }
                }
            mx = max(mx, lis[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (lis[i] == mx)
                ans += cnt[i];
        return ans;
    }
};