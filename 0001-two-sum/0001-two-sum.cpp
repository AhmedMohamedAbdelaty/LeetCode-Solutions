class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int wanted = target - nums[i];
            if (mp[wanted] != 0) {
                return { mp[wanted] - 1, i };
            }
            mp[nums[i]] = i + 1;
        }
        return {};
    }
};