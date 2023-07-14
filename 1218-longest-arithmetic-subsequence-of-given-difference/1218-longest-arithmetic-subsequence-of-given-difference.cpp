class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference)
    {
        int n = arr.size();
        unordered_map<int, int> mp;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            mp[arr[i]] = mp[arr[i] - difference] + 1;
            ans = max(ans, mp[arr[i]]);
        }
        return ans;
    }
};