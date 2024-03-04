class Solution {
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        string ans = "";
        for (int i = 1; i < n; i++) {
            int start = i, end = i;
            // odd length palindrome
            while (start >= 0 && end < n && s[start] == s[end]) {
                start--;
                end++;
            }
            if (end - start - 1 > ans.size()) {
                ans = s.substr(start + 1, end - start - 1);
            }

            // even length palindrome
            start = i - 1;
            end = i;
            while (start >= 0 && end < n && s[start] == s[end]) {
                start--;
                end++;
            }
            if (end - start - 1 > ans.size()) {
                ans = s.substr(start + 1, end - start - 1);
            }
        }
		if (ans.size() == 0) {
			ans = s[0];
		}
		return ans;
    }
};