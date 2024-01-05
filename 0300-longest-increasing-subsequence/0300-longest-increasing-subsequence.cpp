class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        //* First solution: DP O(n^2)
        // return solveDP(nums);
        //* Second solution: Binary Search O(nlogn)
        return solveBINARY(nums);
    }
    int solveDP(vector<int>& nums)
    {
        int n = nums.size(), res = 0;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
    int solveBINARY(vector<int>& nums)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            auto it = lower_bound(res.begin(), res.end(), nums[i]);
            if (it == res.end()) {
                res.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }
        return res.size();
    }
};