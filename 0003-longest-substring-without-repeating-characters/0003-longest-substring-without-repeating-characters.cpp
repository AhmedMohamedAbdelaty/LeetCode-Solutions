class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        if (!n)
            return 0;
        int l = 0, r = 1, ans = 1;
        map<char, int> freq;
        freq[s[0]]++;
        while (r < n) {
            if (freq[s[r]] == 0) {
                freq[s[r]] = 1;
                ans = max(ans, r - l + 1);
                r++;
            } else {
                freq[s[l]] = 0;
                l++;
            }
            if (l == r) {
                freq[s[r]] = 1;
                r++;
            }
        }
        return ans;
    }
};