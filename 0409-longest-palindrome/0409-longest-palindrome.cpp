class Solution {
public:
    int longestPalindrome(string s)
    {
        int freq[128] = { 0 };
        for (char c : s)
            freq[c]++;
        int ans = 0, odd = 0;
        for (int i = 0; i < 128; i++) {
            (freq[i] & 1) ? ans += freq[i] - 1 : ans += freq[i];
            if (freq[i] & 1)
                odd = 1;
        }
        return ans + odd;
    }
};