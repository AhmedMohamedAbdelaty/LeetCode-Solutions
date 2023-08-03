class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.size() == 0)
            return ans;
        vector<string> mp = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        ans.push_back("");
        for (int i = 0; i < digits.size(); i++) {
            vector<string> temp;
            for (int j = 0; j < mp[digits[i] - '0'].size(); j++) {
                for (int k = 0; k < ans.size(); k++) {
                    temp.push_back(ans[k] + mp[digits[i] - '0'][j]);
                }
            }
            ans = temp;
        }
        return ans;
    }
};