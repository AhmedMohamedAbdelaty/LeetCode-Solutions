class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size();
        long long sum = (n*(n+1))/2, sumArr=0;
        for (int i = 0;i<n;i++){
            sumArr+=nums[i];
        }
        int diff= sum - sumArr;
        return diff;
    }
};