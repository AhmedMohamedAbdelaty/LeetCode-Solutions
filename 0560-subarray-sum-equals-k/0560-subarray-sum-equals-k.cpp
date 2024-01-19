class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (mp.find(sum - k) != mp.end()) {
                ans += mp[sum - k];
            }
            mp[sum]++;
        }
        //? mp[0] = 1
        // Example:
        // 1 2 3
        // i = 0, sum = 1, mp[1-3] not found, mp[1]++, mp[1] = 1
        // i = 1, sum = 3, mp[3-3] found, ans += mp[0] = 1, mp[3]++, mp[3] = 1
        // i = 2, sum = 6, mp[6-3] found, ans += mp[3] = 2, mp[6]++, mp[6] = 1
        // ans = 2
        // -----
        // -1 -1 1 , k = 0
        // i = 0, sum = -1, mp[-1-0] not found, mp[-1]++, mp[-1] = 1
        // i = 1, sum = -2, mp[-2-0] not found, mp[-2]++, mp[-2] = 1
        // i = 2, sum = -1, mp[-1-0] found, ans += mp[-1] = 1, mp[-1]++, mp[-1] = 2
        // ans = 1
        // -----
        // 1 1 1 , k = 2
        // i = 0, sum = 1, mp[1-2] not found, mp[1]++, mp[1] = 1
        // i = 1, sum = 2, mp[2-2] found, ans += mp[0] = 1, mp[2]++, mp[2] = 1
        // i = 2, sum = 3, mp[3-2] found, ans += mp[1] = 2, mp[3]++, mp[3] = 1
        // ans = 2
        return ans;
    }
};