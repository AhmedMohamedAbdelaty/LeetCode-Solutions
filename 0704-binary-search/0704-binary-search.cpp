class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int n = nums.size();
        int l = 0, r = n - 1, mid = 0;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};