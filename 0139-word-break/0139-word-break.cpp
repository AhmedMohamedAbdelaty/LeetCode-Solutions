class Solution {
    vector<int> dp;
    string s;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        this->s = s;
        dp.resize(s.size(), -1);
        return solve(0, wordDict);
    }
    bool solve(int i, vector<string>& wordDict) {
        if (i == s.size())
            return true;
        if (dp[i] != -1)
            return dp[i];
        bool ans = false;
        for (auto& x : wordDict) {
            if (i + x.size() <= s.size() && s.substr(i, x.size()) == x) {
                ans |= solve(i + x.size(), wordDict);
            }
        }
        return dp[i] = ans;
    }
};