class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> ans;
        map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++) {
            string org = strs[i];
            sort(strs[i].begin(), strs[i].end());
            mp[strs[i]].push_back(org);
        }
        sort(strs.begin(), strs.end());
        vector<string> temp;
        for (auto i : mp) {
            temp.clear();
            for (auto j : i.second) {
                temp.push_back(j);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};