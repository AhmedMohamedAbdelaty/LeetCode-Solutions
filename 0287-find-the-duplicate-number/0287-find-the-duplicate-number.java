class Solution {
    public int findDuplicate(int[] nums)
    {
        int len = nums.length;
        int l = 1, r = len - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            int cnt = 0;
            for (int i = 0; i < len; i++) {
                if (nums[i] <= mid)
                    cnt++;
            }
            if (cnt > mid)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
}