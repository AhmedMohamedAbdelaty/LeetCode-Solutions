class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge)
    {
        map<string, string> mp;
        for (int i = 0; i < knowledge.size(); i++) {
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                string key;
                i++;
                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                } else {
                    ans += '?';
                }
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};