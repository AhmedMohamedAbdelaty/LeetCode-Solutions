class Solution {
public:
    bool containsDuplicate(vector<int>& nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        unordered_map<int, int> mp;
        for (auto& x : nums) {
            mp[x]++;
            if (mp[x] > 1)
                return true;
        }
        return false;
    }
};