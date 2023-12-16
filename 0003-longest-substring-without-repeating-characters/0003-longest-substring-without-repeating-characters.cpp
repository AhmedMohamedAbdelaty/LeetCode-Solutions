class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size(), ans = 0;
        vector<int> cnt(256, 0);
        for (int l = 0, r = 0; r < n; r++) {
            cnt[s[r]]++;
            while (cnt[s[r]] > 1) {
                cnt[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};