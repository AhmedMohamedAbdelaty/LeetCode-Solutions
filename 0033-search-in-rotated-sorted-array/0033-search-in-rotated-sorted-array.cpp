class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n, l, r, mid;
        n = nums.size();
        l = 0, r = n - 1;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] >= nums[l]) {
                if (target >= nums[l] && target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            } else {
                if (target <= nums[r] && target > nums[mid])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};