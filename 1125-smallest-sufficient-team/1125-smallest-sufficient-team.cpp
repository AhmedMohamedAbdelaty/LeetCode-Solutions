class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people)
    {
        int n = req_skills.size();
        unordered_map<int, vector<int>> dp;
        dp.reserve(1 << n);
        dp[0] = {};
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            mp[req_skills[i]] = i;
        }
        for (int i = 0; i < people.size(); i++) {
            int mask = 0;
            for (auto& x : people[i]) {
                mask |= (1 << mp[x]);
            }
            for (auto& [key, val] : dp) {
                int nmask = key | mask;
                if (dp.find(nmask) == dp.end() || dp[nmask].size() > val.size() + 1) {
                    dp[nmask] = val;
                    dp[nmask].push_back(i);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};