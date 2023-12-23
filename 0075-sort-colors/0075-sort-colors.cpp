class Solution {

public:
    void sortColors(vector<int>& nums)
    {
        int n = nums.size();
        int start = 0, middle = 0, end = n - 1;
        while (middle <= end) {
            if (nums[middle] == 0) {
                swap(nums[start], nums[middle]);
                start++;
                middle++;
            } else if (nums[middle] == 1) {
                middle++;
            } else {
                swap(nums[middle], nums[end]);
                end--;
            }
        }
    }
};