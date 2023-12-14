class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return nums[n/2];
    }
};